program example1F90
   use,intrinsic :: iso_c_binding
   use SNLPF90
   implicit NONE
   
   integer(kind=c_int)  :: n = 2
   integer(kind=c_int)  :: m = 0
   integer(kind=c_int)  :: p = 1
   type(SNLP)           :: s
   integer(kind=c_int)  :: exit_code,i
   real(kind=c_double),dimension(:),pointer  ::x
   
   allocate(x(n))
   x = [-2.9,2.0]
   
   !s = SNLPNewF90(n,m,p,c_funloc(fhg),c_null_funptr,c_null_ptr)
   s%n                         = n
   s%m                         = m
   s%p                         = p
   s%fhg                       = c_funloc(fhg)
   s%Dfhg                      = c_null_funptr
   s%ctx                       = c_null_ptr
   s%tolerance                 = 1.e-6
   s%maximum_iterations        = 500
   s%show_progress             = 1
   s%print_function_gradient   = 0
   s%print_constraint_gradient = 0
   s%simple_line_search        = 0

   s%f                         = 0
   s%normc                     = 0
   s%normT                     = 0
   s%lambda                    = 0
   s%mu                        = 0
   s%number_of_function_calls  = 0
   s%number_of_gradient_calls  = 0
   s%number_of_SOC             = 0
   s%number_of_QP_solves       = 0
   s%exit_code                 = 0

   exit_code = SNLPL1SQPF90(s,x)
        
   write(*,*) "exit code: ", exit_code
   write(*,*) "x: ", x

   deallocate(x)
contains
   subroutine fhg(x,f,h,g,ctx) bind(c)
      real(kind=c_double)   :: x(*)
      real(kind=c_double)   :: f(*)
      real(kind=c_double)   :: h(*)
      real(kind=c_double)   :: g(*)
      type(c_ptr)           :: ctx
      
      f(1) = 100.0*(x(2)-x(1)*x(1))*(x(2)-x(1)*x(1)) + (1-x(1))*(1-x(1));
      g(1) = x(1)*x(1) + x(2)*x(2) - 1.5
   end subroutine fhg
end program example1F90
