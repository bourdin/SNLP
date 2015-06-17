module example1F90_mod
   !!! note that this type is NOT C interoperable, which is not an issue, since we only
   !!! need SNLP to carry its address
   type :: ctx 
      integer                       :: a
      real                          :: b
      real,dimension(:,:),pointer   :: array
   end type ctx
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

contains
   subroutine fhg(x,f,h,g,c) bind(c)
      use,intrinsic :: iso_c_binding
      real(kind=c_double)           :: x(*)
      real(kind=c_double)           :: f(*)
      real(kind=c_double)           :: h(*)
      real(kind=c_double)           :: g(*)
      type(c_ptr),intent(in),value  :: c
      type(ctx),pointer             :: myctx

      !!! This is the fortran equivalent of casting c into a myctx
      call c_f_pointer(c,myctx)      
      
      !write(*,*) "this is fhg"
      !write(*,*) 'myctx%a,myctx%b ',myctx%a,myctx%b
      !write(*,*) 'myctx%array      ',myctx%array
      f(1) = myctx%b*(x(2)-x(1)*x(1))*(x(2)-x(1)*x(1)) + (1-x(1))*(1-x(1));
      g(1) = x(1)*x(1) + x(2)*x(2) - 1.5
   end subroutine fhg
end program example1F90
