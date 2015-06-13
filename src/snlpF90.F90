module SNLP_mod
   use, intrinsic :: iso_c_binding
   implicit NONE
   
   integer, parameter  :: SNLP_mmax = 10
   
   type,bind(C) :: SNLP
      integer(kind=c_int)   :: n  ! number of parameters
      integer(kind=c_int)   :: m  ! number of equality constraints
      integer(kind=c_int)   :: p  ! number of inequality constraints
      type(c_funptr)        :: fhg
      type(c_funptr)        :: Dfhg
      type(c_ptr)           :: ctx
      real(kind=c_double)   :: tolerance                   ! 1.0e-6
      integer(kind=c_int)   :: maximum_iterations          ! 500
      integer(kind=c_int)   :: show_progress               ! NO
      integer(kind=c_int)   :: print_function_gradient     ! default: NO
      integer(kind=c_int)   :: print_constraint_gradient   ! default: NO
      integer(kind=c_int)   :: simple_line_search          ! default: NO

      ! Results
      real(kind=c_double)   :: f
      real(kind=c_double)   :: normc
      real(kind=c_double)   :: normT
      real(kind=c_double)   :: lambda(SNLP_mmax)
      real(kind=c_double)   :: mu(SNLP_mmax)
      integer(kind=c_int)   :: number_of_iterations
      integer(kind=c_int)   :: number_of_function_calls
      integer(kind=c_int)   :: number_of_gradient_calls
      integer(kind=c_int)   :: number_of_QP_solves
      integer(kind=c_int)   :: number_of_SOC
      integer(kind=c_int)   :: exit_code
   end type SNLP
end module SNLP_mod

module SNLPF90
   use,intrinsic :: iso_c_binding
   use SNLP_mod
   
   interface 
      subroutine SNLPLinfSQP(s,x) bind(c)
         use,intrinsic :: iso_c_binding
         use SNLP_mod
         type(SNLP)                          :: s
         real(kind=c_double),intent(inout)   :: x(*)
      end subroutine
   end interface   

   interface 
      subroutine SNLPL1SQP(s,x) bind(c)
         use,intrinsic :: iso_c_binding
         use SNLP_mod
         type(SNLP)                          :: s
         real(kind=c_double),intent(inout)   :: x(*)
      end subroutine
   end interface   

Contains
#undef __FUNCT__ 
#define __FUNCT__ "SNLPF90New"
   function SNLPF90New(n,m,p,fhg,Dfhg,ctx)
      type(SNLP)            :: SNLPF90New
      integer(kind=c_int)   :: n  ! number of parameters
      integer(kind=c_int)   :: m  ! number of equality constraints
      integer(kind=c_int)   :: p  ! number of inequality constraints
      type(c_funptr)        :: fhg
      type(c_funptr)        :: Dfhg
      type(c_ptr)           :: ctx
      
      if (n < 1) then
         write(*,*) "SNLPNew(): n < 1: invalid number of parameters"
         return
      end if
      if ((m > n) .OR. (m < 0)) then
         write(*,*) "SNLPNew(): m < 0 or m > n: invalid number of equality constraints"
         return
      end if
      if (m > SNLP_mmax) then
         write(*,100) m,SNLP_mmax,__FILE__
         100 format("SNLPNew(): m = ",I," > ", I, "increase the value of SNLP_mmax in ",A)
         !SNLPNew = s
         return
      end if
      if (p < 0) then
         write(*,*) "SNLPNew(): p < 0: invalid number of inequality constraints"
         return
      end if
      !if (fhg == c_null_funptr) then
      !   write(*,*) "SNLPNew(): NULL pointer to function evaluator"
      !   SNLPNew = s
      !   return
      !end if
      SNLPF90New%n                         = n
      SNLPF90New%m                         = m
      SNLPF90New%p                         = p
      SNLPF90New%fhg                       = fhg
      SNLPF90New%Dfhg                      = Dfhg
      SNLPF90New%ctx                       = ctx
      SNLPF90New%tolerance                 = 1.e-6
      SNLPF90New%maximum_iterations        = 500
      SNLPF90New%show_progress             = 0
      SNLPF90New%print_function_gradient   = 0
      SNLPF90New%print_constraint_gradient = 0
      SNLPF90New%simple_line_search        = 0

      !!! Results
      SNLPF90New%f                         = 0
      SNLPF90New%normc                     = 0
      SNLPF90New%normT                     = 0
      SNLPF90New%lambda                    = 0
      SNLPF90New%mu                        = 0
      SNLPF90New%number_of_function_calls  = 0
      SNLPF90New%number_of_gradient_calls  = 0
      SNLPF90New%number_of_SOC             = 0
      SNLPF90New%number_of_QP_solves       = 0
      SNLPF90New%exit_code                 = 0
   end function 
end module SNLPF90
