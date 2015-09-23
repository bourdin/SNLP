!!! Copyright (c) 2015  B. Bourdin bourdin@lsu.edu
!!!                     E. Tanné erwan.tanne@gmail.com
!!!                     A. Mesgarnejad a.mesgarnejad@gmail.com
!!! All rights reserved.
!!! Use of this source code is governed by a BSD-style
!!! license that can be found in the license.txt file.

module example1F90_mod
   !!! note that this type is NOT C interoperable, which is not an issue, since we only
   !!! need SNLP to carry its address
   type :: ctx 
      integer                       :: a
      real                          :: b
      real,dimension(:,:),pointer   :: array
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

      !!! This is the fortran equivalent of casting myctx into a c_ptr
      call c_f_pointer(myctx,myctx_ptr)      
      
      !write(*,*) "this is fhg"
      !write(*,*) 'myctx_ptr%a,myctx_ptr%b ',myctx_ptr%a,c_ptr%b
      !write(*,*) 'myctx_ptr%array      ',myctx_ptr%array
      f(1) = myctx_ptr%b * (x(2)-x(1)**2)**2 + (1.-x(1))**2
      g(1) = x(1)**2 + x(2)**2 - 1.5
   end subroutine fhg
end module example1F90_mod

program example1F90ctx
   use,intrinsic :: iso_c_binding
   use SNLPF90
   use example1F90_mod
   implicit NONE
   
   integer(kind=c_int)  :: n = 2
   integer(kind=c_int)  :: m = 0
   integer(kind=c_int)  :: p = 1
   type(SNLP),pointer   :: s
   integer              :: i,j
   integer(kind=c_int)  :: exit_code
   real(kind=c_double),dimension(:),pointer  ::x
   type(ctx),target     :: myctx
   
   myctx%a = 1.
   myctx%b = 100.
   allocate(myctx%array(2,3))
   do i = 1,2
      do j = 1,3
         myctx%array(i,j) = 100*i+j
      end do
   end do
   allocate(x(n))
   x = [-2.9,2.0]
   
   call SNLPNew(s,n,m,p,c_funloc(fhg),c_null_funptr,c_loc(myctx))
   s%show_progress = 1
   
   exit_code = SNLPL1SQP(s,x)
   write(*,*) 'exit_code: ',exit_code
   write(*,*) 'x:         ',x
   call SNLPDelete(s)
   deallocate(x)

end program example1F90ctx
