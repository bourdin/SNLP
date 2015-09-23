!!! Copyright (c) 2015  B. Bourdin bourdin@lsu.edu
!!!                     E. Tanné erwan.tanne@gmail.com
!!!                     A. Mesgarnejad a.mesgarnejad@gmail.com
!!! All rights reserved.
!!! Use of this source code is governed by a BSD-style
!!! license that can be found in the license.txt file.

module example1F90_mod

contains
   subroutine fhg(x,f,h,g,ctx) bind(c)
      use,intrinsic :: iso_c_binding
      real(kind=c_double)   :: x(*)
      real(kind=c_double)   :: f(*)
      real(kind=c_double)   :: h(*)
      real(kind=c_double)   :: g(*)
      type(c_ptr)           :: ctx
      
      f(1) = 100.0 * (x(2)-x(1)**2)**2 + (1.-x(1))**2
      g(1) = x(1)**2 + x(2)**2 - 1.5
   end subroutine fhg
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
   integer(kind=c_int)  :: exit_code
   real(kind=c_double),dimension(:),pointer  ::x
   
   allocate(x(n))
   x = [-2.9,2.0]
   
   call SNLPNew(s,n,m,p,c_funloc(fhg),c_null_funptr,c_null_ptr)
   s%show_progress = 1
   
   exit_code = SNLPL1SQP(s, x)
   write(*,*) 'exit_code: ',exit_code
   write(*,*) 'x:         ',x
   call SNLPDelete(s)
   deallocate(x)
end program example1F90
