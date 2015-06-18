module example1F90_mod

contains
   subroutine fhg(x,f,h,g,ctx) bind(c)
      use,intrinsic :: iso_c_binding
      real(kind=c_double)   :: x(*)
      real(kind=c_double)   :: f(*)
      real(kind=c_double)   :: h(*)
      real(kind=c_double)   :: g(*)
      type(c_ptr)           :: ctx
      
      f(1)   = x(1) + 2.*x(2) + 4.*x(5) + exp(x(1) * x(4))
      h(1:6) = [x(1) + 2.*x(2) + 5.*x(5) - 6.,   &
                x(1) + x(2) + x(3) - 3.,         &
                x(4) + x(5) + x(6) - 2.,         &
                x(1) + x(4) - 1.,                &
                x(2) + x(5) - 2.,                &
                x(3) + x(6) - 2.]
      g(1:8) = [-x(1), x(1) - 1., -x(2), -x(3), -x(4), x(4)-1., -x(5), -x(6)]
   end subroutine fhg
end module example1F90_mod

program example1F90
   use,intrinsic :: iso_c_binding
   use SNLPF90
   use example1F90_mod
   implicit NONE
   
   integer(kind=c_int)  :: n = 6
   integer(kind=c_int)  :: m = 6
   integer(kind=c_int)  :: p = 8
   type(SNLP),pointer   :: s
   integer(kind=c_int)  :: exit_code
   real(kind=c_double),dimension(:),pointer  ::x
   
   allocate(x(n))
   x = [1.,2.,0.,0.,0.,2.]
   
   call SNLPNew(s,n,m,p,c_funloc(fhg),c_null_funptr,c_null_ptr)
   s%show_progress = 1
   s%print_function_gradient = 1
   s%print_constraint_gradient = 1
   s%simple_line_search = 1

   
   exit_code = SNLPL1SQP(s, x)
   write(*,*) 'exit_code: ',exit_code
   write(*,*) 'x:         ',x
   call SNLPDelete(s)
   deallocate(x)
end program example1F90
