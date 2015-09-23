!!! Copyright (c) 2015  B. Bourdin bourdin@lsu.edu
!!!                     E. Tanné erwan.tanne@gmail.com
!!!                     A. Mesgarnejad a.mesgarnejad@gmail.com
!!! All rights reserved.
!!! Use of this source code is governed by a BSD-style
!!! license that can be found in the license.txt file.

module example5F90_mod
   implicit NONE
   !!! note that this type is NOT C interoperable, which is not an issue, since we only
   !!! need SNLP to carry its address
   type :: ctx 
      real,dimension(3,3)           :: A
      real,dimension(3)             :: b,p
      real                          :: sigmac
   end type ctx
contains
   subroutine fhg(x,f,h,g,myctx) bind(c)
      use,intrinsic :: iso_c_binding
      real(kind=c_double)           :: x(*)
      real(kind=c_double)           :: f(*)
      real(kind=c_double)           :: h(*)
      real(kind=c_double)           :: g(*)
      type(c_ptr),intent(in),value  :: myctx
      type(ctx),pointer             :: myctx_ptr

      !!! This is the fortran equivalent of casting ctx into a c_ptr
      call c_f_pointer(myctx,myctx_ptr)      
      
      f(1) = dot_product(matmul(myctx_ptr%A,x(1:3)-myctx_ptr%p),x(1:3)-myctx_ptr%p)/2. - dot_product(x(1:3),myctx_ptr%b)

      h(1) = sum(x(1:3))

      g(1) =  x(1) - x(2) - myctx_ptr%sigmac
      g(2) = -x(1) + x(2) - myctx_ptr%sigmac
      g(3) =  x(1) - x(3) - myctx_ptr%sigmac
      g(4) = -x(1) + x(3) - myctx_ptr%sigmac
      g(5) =  x(2) - x(3) - myctx_ptr%sigmac
      g(6) = -x(2) + x(3) - myctx_ptr%sigmac
   end subroutine fhg

   subroutine Dfhg(x,Df,Dh,Dg,myctx) bind(c)
      use,intrinsic :: iso_c_binding
      real(kind=c_double)           :: x(*)
      real(kind=c_double)           :: Df(*)
      type(c_ptr)                   :: Dh
      type(c_ptr)                   :: Dg
      type(c_ptr),value             :: myctx
      type(ctx),pointer             :: myctx_ptr

      real(kind=c_double),dimension(:), pointer    :: Dhptr      
      real(kind=c_double),dimension(:,:), pointer  :: Dgptr      

      !!! This is the fortran equivalent of casting ctx into a c_ptr
      call c_f_pointer(myctx,myctx_ptr)      
      Df(1:3) = matmul(myctx_ptr%A,x(1:3)-myctx_ptr%p) - myctx_ptr%b

      call c_f_pointer(Dh,Dhptr,[3])
      Dhptr = 1.
      
      !!! remember that fortran uses column-major ordering whereas C uses row-major ordering
      !!! so that we need to compute Dg^t instead of Dg
      call c_f_pointer(Dg,Dgptr,[3,6])
      Dgptr(1:3,1) = [1., -1.,  0.]
      Dgptr(1:3,2) = [-1., 1.,  0.]
      Dgptr(1:3,3) = [1.,  0., -1.]
      Dgptr(1:3,4) = [-1., 0.,  1.]
      Dgptr(1:3,5) = [0.,  1., -1.]
      Dgptr(1:3,6) = [0., -1.,  1.]

   end subroutine Dfhg
end module example5F90_mod

program example5F90
   use,intrinsic :: iso_c_binding
   use SNLPF90
   use example5F90_mod
   implicit NONE
   
   integer(kind=c_int)  :: n = 3
   integer(kind=c_int)  :: m = 1
   integer(kind=c_int)  :: p = 6
   type(SNLP),pointer   :: s
   integer              :: i,j
   integer(kind=c_int)  :: exit_code
   real(kind=c_double),dimension(:),pointer  ::x
   type(ctx),target     :: ctx_ptr
   
   ctx_ptr%A = 0.
   ctx_ptr%A(1,1) = 1.
   ctx_ptr%A(2,2) = 2.
   ctx_ptr%A(3,3) = 5.

   ctx_ptr%b = 0

   ctx_ptr%p = [-1.,2.,-5.]
   ctx_ptr%sigmac = 1.
   
   allocate(x(n))
   x = 0.
   
   call SNLPNew(s,n,m,p,c_funloc(fhg),c_funloc(Dfhg),c_loc(ctx_ptr))
   s%show_progress = 1
   
   exit_code = SNLPL1SQP(s,x)
   write(*,*) 'exit_code: ',exit_code
   write(*,*) 'x:         ',x
   call SNLPDelete(s)
   deallocate(x)

end program example5F90
