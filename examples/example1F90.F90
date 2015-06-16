program example1F90
   use,intrinsic :: iso_c_binding
   use SNLPF90
   implicit NONE
   
   integer(kind=c_int)  :: n = 2
   integer(kind=c_int)  :: m = 0
   integer(kind=c_int)  :: p = 1
   type(SNLP),pointer   :: s
   integer(kind=c_int)  :: exit_code
   real(kind=c_double),dimension(:),pointer  ::x
   
   allocate(x(n))
   x = [-2.9,2.0]
   
   call SNLPNew(s,n,m,p,c_funloc(fhg),c_null_funptr,c_null_ptr)
   s%show_progress = 1
   
   exit_code = SNLPL1SQPF90(s, x)
   write(*,*) 'exit_code: ',exit_code
   write(*,*) 'x:         ',x
   call SNLPDelete(s)
   deallocate(x)
contains
   subroutine fhg(x,f,h,g,ctx)
      real(kind=c_double)   :: x(*)
      real(kind=c_double)   :: f(*)
      real(kind=c_double)   :: h(*)
      real(kind=c_double)   :: g(*)
      type(c_ptr)           :: ctx
      
      f(1) = 100.0*(x(2)-x(1)*x(1))*(x(2)-x(1)*x(1)) + (1-x(1))*(1-x(1));
      g(1) = x(1)*x(1) + x(2)*x(2) - 1.5
   end subroutine fhg
end program example1F90
