!!! Copyright (c) 2015  B. Bourdin bourdin@lsu.edu
!!!                     E. Tanné erwan.tanne@gmail.com
!!!                     A. Mesgarnejad a.mesgarnejad@gmail.com
!!! All rights reserved.
!!! Use of this source code is governed by a BSD-style
!!! license that can be found in the license.txt file.

module SNLP_mod
   use, intrinsic :: iso_c_binding
   implicit NONE
   
!!! Remark that fortran C interoperability does not support assumed size 
!!! allocatable arrays inside an interoperable derived type
!!! fortran cannot access the lambda and mu array directly.
!!! They need to be converted into fortran pointer or allocatable first
!!!    real(kind=c_double),pointer                    :: lambda(:),mu(:)
!!!    call c_f_pointer(SNLP%lambda,lambda,[SNLP(m)])
!!!    call c_f_pointer(SNLP%mu,mu,[SNLP(p)])
!!! lambda and mu should not be deallocated as it free SNLP%lambda and SNLP%mu.
!!!

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
      type(c_ptr)           :: lambda
      type(c_ptr)           :: mu
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
   Private
   public :: SNLPNew
   public :: SNLPDelete
   public :: SNLPLinfSQP
   public :: SNLPL1SQP
   public :: SNLP
   
   interface
      function SNLPNew_private(n,m,p,fhg,Dfhg,ctx) bind(c,name='SNLPNew')
         use,intrinsic ::  iso_c_binding
         use SNLP_mod

         type(c_ptr)                            :: SNLPNew_private
         integer(kind=c_int),intent(IN),value   :: n,m,p
         type(c_funptr),value                   :: fhg,Dfhg
         type(c_ptr),value                      :: ctx
      end function SNLPNew_private
   end interface
   
   interface 
      subroutine SNLPDelete_private(s) bind(c,name='SNLPDelete')
         use,intrinsic ::  iso_c_binding
         use SNLP_mod
         
         type(c_ptr),value                      :: s
      end subroutine SNLPDelete_private
   end interface    

   interface 
      function SNLPL1SQP(s,x) bind(c,name='SNLPL1SQP')
         use,intrinsic :: iso_c_binding
         use SNLP_mod

         type(SNLP),intent(inout)               :: s
         real(kind=c_double),intent(inout)      :: x(*)
         integer(kind=c_int)                    :: SNLPL1SQP
      end function SNLPL1SQP
   end interface   

   interface 
      function SNLPLinfSQP(s,x) bind(c,name='SNLPLinfSQP')
         use,intrinsic :: iso_c_binding
         use SNLP_mod

         type(SNLP),intent(inout)               :: s
         real(kind=c_double),intent(inout)      :: x(*)
         integer(kind=c_int)                    :: SNLPLinfSQP
      end function SNLPLinfSQP
   end interface   
Contains
   subroutine SNLPNew(s,n,m,p,fhg,Dfhg,ctx)
      type(SNLP),pointer,intent(out)         :: s
      integer(kind=c_int),intent(IN)         :: n,m,p
      type(c_funptr),value                   :: fhg,Dfhg
      type(c_ptr)                            :: ctx

      type(c_ptr)                            :: cptr
      cptr = SNLPNew_private(n,m,p,fhg,Dfhg,ctx)
      call c_f_pointer(cptr,s)
   end subroutine SNLPNew
   
   
   subroutine SNLPDelete(s)
      type(SNLP),pointer,intent(inout)       :: s

      call SNLPDelete_private(c_loc(s))
   end subroutine SNLPDelete
end module SNLPF90
