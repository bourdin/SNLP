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

      !!! This is the fortran equivalent of casting ctx into a c_ptr
      call c_f_pointer(myctx,myctx_ptr)      
      
      f(1) = myctx_ptr%b * (x(2)-x(1)**2)**2 + (1.-x(1))**2
      g(1) = x(1)**2 + x(2)**2 - 1.5
   end subroutine fhg

   subroutine Dfhg(x,Df,Dh,Dg,myctx) bind(c)
      use,intrinsic :: iso_c_binding
      real(kind=c_double)           :: x(*)
      real(kind=c_double)           :: Df(*)
      type(c_ptr)                   :: Dh
      type(c_ptr)                   :: Dg
      type(c_ptr),value             :: myctx
      type(ctx),pointer             :: myctx_ptr

      real(kind=c_double),dimension(:,:), pointer  :: Dgptr      

      Df(1) = -2. * myctx_ptr%b * x(1)*(x(2)-x(1)**2) - 2.0*(1.-x(1));
      Df(2) = myctx_ptr%b*(x(2)-x(1)**2);

      call c_f_pointer(Dg,Dgptr,[1,2])
      Dgptr(1,1) = 2.0*x(1);
      Dgptr(1,2) = 2.0*x(2);
   end subroutine Dfhg
end module example1F90_mod

program example1F90
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
   type(ctx),target     :: ctx_ptr
   
   ctx_ptr%a = 1.
   ctx_ptr%b = 100.
   allocate(ctx_ptr%array(2,3))
   do i = 1,2
      ctx_ptr%array(i,:) = [(100*i+j, j = 1, 3)]
   end do
   write(*,*) ctx_ptr%array
   allocate(x(n))
   x = [-2.9,2.0]
   
   call SNLPNew(s,n,m,p,c_funloc(fhg),c_null_funptr,c_loc(ctx_ptr))
   s%show_progress = 1
   
   exit_code = SNLPL1SQP(s,x)
   write(*,*) 'exit_code: ',exit_code
   write(*,*) 'x:         ',x
   call SNLPDelete(s)
   deallocate(x)

end program example1F90
