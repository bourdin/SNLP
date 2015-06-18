module example2F90_mod

contains
   subroutine fhg(x,f,h,g,ctx) bind(c)
      use,intrinsic :: iso_c_binding
      real(kind=c_double)   :: x(*)
      real(kind=c_double)   :: f(*)
      real(kind=c_double)   :: h(*)
      real(kind=c_double)   :: g(*)
      type(c_ptr)           :: ctx
      
      f(1) = 100. * (x(2)-x(1)**2)**2 + (1.-x(1))**2
      g(1) = x(1)**2 + x(2)**2 - 1.5
   end subroutine fhg

   subroutine Dfhg(x,Df,Dh,Dg,ctx) bind(c)
      use,intrinsic :: iso_c_binding
      real(kind=c_double)   :: x(*)
      real(kind=c_double)   :: Df(*)
      type(c_ptr)           :: Dh
      type(c_ptr)           :: Dg
      type(c_ptr)           :: ctx

      real(kind=c_double),dimension(:,:), pointer  :: Dgptr      

      Df(1) = -400.0*x(1)*(x(2)-x(1)*x(1)) - 2.0*(1-x(1));
      Df(2) = 200.0*(x(2)-x(1)*x(1));

      call c_f_pointer(Dg,Dgptr,[1,2])
      Dgptr(1,1) = 2.0*x(1);
      Dgptr(1,2) = 2.0*x(2);
   end subroutine Dfhg
end module example2F90_mod

program example2F90
   use,intrinsic :: iso_c_binding
   use SNLPF90
   use example2F90_mod
   implicit NONE
   
   integer(kind=c_int)  :: n = 2
   integer(kind=c_int)  :: m = 0
   integer(kind=c_int)  :: p = 1
   type(SNLP),pointer   :: s
   integer(kind=c_int)  :: exit_code
   real(kind=c_double),dimension(:),pointer  ::x
   
   allocate(x(n))
   x = [-2.9,2.0]
   
   call SNLPNew(s,n,m,p,c_funloc(fhg),c_funloc(Dfhg),c_null_ptr)
   s%show_progress = 1
   
   exit_code = SNLPL1SQP(s, x)
   write(*,*) 'exit_code: ',exit_code
   write(*,*) 'x:         ',x
   call SNLPDelete(s)
   deallocate(x)
end program example2F90
