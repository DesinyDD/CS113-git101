Pointers

One of the most powerful features available to a C programmer is the ability to manipulate computer memory directly by using pointers.

1. What are pointers?

Pointers are variables that contain memory addresses as their values. Normally, a variable directly contains a specific value. A pointer, on the other hand, contains an address of a variable that contains a specific value.

Pointers, like any other variables, must be declared before they can be used. The declaration

int *countPtr, count;
declares the variable countPtr to be of type int * (i.e. a pointer to an integer value) and is read, "countPtr is a pointer to int" or "countPtr points to an object of type integer." Also, the variable count is declared to be an integer, not a pointer to an integer. The * only applies to countPtr in the declaration. When * is used in this manner in a declaration, it indicates that the variable being declared is a pointer. Pointers can be declared to point to objects of any data type.

Pointers should be initialized either when they are declared or in an assignment statement. A pointer may be initialized to 0, NULL or an address. A pointer with the value NULL points to nothing. NULL is a symbolic constant defined in the <stdio.h> header file. Initializing a pointer to 0 is equivalent to initializing a pointer to NULL, but NULL is preferred.

2. Pointer Operators

The &, or address operator, is a unary operator that returns the address of its operand. For example, assuming the declarations

int y = 5;
int *yPtr;
the statement

yPtr = &y;
assigns the address of the variable y to pointer variable yPtr.

The * operator, commonly referred to as the indirection operator or dereferencing operator, returns the value of the object to which its operand (i.e. a pointer) points. For example, the statement

printf ("%d", *yPtr);
prints the value of variable y, namely 5. Using * in this manner is called dereferencing a pointer.

The printf conversion specification %p outputs the memory location as a hexadecimal integer. The & and * operators are complements of one another -- when they are both applied consecutively to yPtr in either order, the same result is printed.

* Here is the example of pointers, sample08a.c.

#include <stdio.h>
 
main ()
{  int a;
   int *aPtr;
 
   a = 10;
   aPtr = &a;
 
   printf("a = %d, *aPtr = %d (1)\n",a,*aPtr);
 
   *aPtr *= 2;
 
   printf("a = %d, *aPtr = %d (2)\n\n",a,*aPtr);
 
   printf("The address of a is %p\n"
           "The value of aPtr is %p\n\n",&a,aPtr);
 
   printf("&*aPtr = %p\n*&aPtr = %p\n",&*aPtr,*&aPtr);
}
3. Calling Functions by Reference

There are two ways to pass arguments to a function -- call by value and call by reference. All function calls in C are call by value. As we saw in Chapter 5, return may be used to return onevalue from a called function to a caller. However, many functions require the capability to modify one or more variables in the caller. For this purpose, C provides the capabilities for simulating call by reference.

In C, programmers use pointers and the indirection operator to simulate call by reference. When calling a function with arguments that should be modified, the addresses of arguments are passed. This is normally accomplished by applying the address operator (&) to the variable whose value will be modified.

As we saw previously, arrays are not passed using operator & because C automatically passes the starting location in memory of the array (the name of an array is equivalent to &arrayName[0]). When the address of a variable is passed to a function, the indirection operator (*) may be used in the function to modify the value at that location in the caller's memory.

* Another example on pointers, sample08b.c.

#include <stdio.h>
 
int cubeByValue(int);           /* function prototype */
void cubeByReference(int *);    /* function prototype */
 
main ()
{  int a = 3;
   int b = 4;
 
   printf("The original value of a is %d\n",a);
   a = cubeByValue (a);
   printf("The new value of a is %d\n\n",a);
 
   printf("The original value of b is %d\n",b);
   cubeByReference(&b);
   printf("The new value of b is %d\n",b);
}
 
int cubeByValue(int val)
{
   return val * val * val;
}
 
void cubeByReference(int *val)
{
   *val = *val * *val * *val;
}
4. Using the const Qualifier with Pointers

The const qualifier enables the programmer to inform the compiler that the value of a particular variable should not be modified. The const qualifier did not exist in early versions of C; it was added to the language by the ANSI C committee.

Although const is well defined in ANSI C, some systems do not enforce it.

* The example on const, sample08c.c.

f1(const int arr[])
{ int i;
  int sum;
 
  for (i=sum=0;i < 10;i++)
     sum += arr[i];
 
  /* Add the statement,
     arr[5] = 10;
     and see if the compiler allows you to do so! */
 
  return sum;
}
 
main ()
{ int a[] = {1,2,3,4,5,6,7,8,9,10};
  int sum;
 
  sum = f1 (a);
  printf("sum  = %d\n",sum);
  printf("a[5] = %d\n",a[5]);
}
5. Pointer Expressions and Pointer Arithmetic

Pointer are valid operands in arithmetic expression, assignment expressions, and comparison expressions. However, not all the operators normally used in these expressions are valid in conjunction with pointer variables. A pointer may be incremented (++) or decremented (--), an integer may be added to a pointer (+ or +=), an integer may be subtracted from a pointer (- or -=), or one pointer may be subtracted from another.

int v[7],*vPtr;
vPtr = v;
vPtr = &v[0];
vPtr += 2;
In conventional arithmetic, the addition 3000+2 yields the value 3002. This is normally not the case with pointer arithmetic. When an integer is added to or subtracted from a pointer, the pointer is not simply incremented or decremented by that integer, but by that integer times the size of the object to which the pointer refers.

Pointer variables may be subtracted from one another. Assume that vPtr and vPtr2 are both pointers to an integer.

vPtr = &v[0];
vPtr2 = &v[4];
The statement

x = vPtr2 - vPtr;
would assign to x the number of array elements from vPtr to vPtr2, in this case, 4.

* Here is the example, sample08d.c.

main ()
{  int arr[] = {0, 100, 200, 300, 400, 500, 600, 700};
   int *ptr1, *ptr2;
 
   ptr1 = arr;
   ptr2 = arr+3;
 
   printf("*ptr1   = %d, *ptr2   = %d\n", *ptr1, *ptr2);
   printf("ptr1[0] = %d, ptr2[0] = %d\n\n", ptr1[0], ptr2[0]);
 
   printf("ptr1[1] = %d, ptr2[1] = %d\n\n", ptr1[1], ptr2[1]);
 
   printf("*(ptr1+5) = %d\n\n",*(ptr1+5));
   printf("Address of ptr1  = %p, Address of ptr1+1 = %p\n\n", ptr1, ptr1+1);
 
   printf("Address of arr   = %p\n", arr);
   printf("Address of arr+2 = %p\n", arr+2);
 
   /* arr += 3; */
   /* is an invalid because it attempts to modify */
   /* the value of the array name                 */
}
6. Pointers to Functions

A pointer to a function contains the address of the function in memory. In this Chapter, we saw that an array name is really the address in memory of the first element of the array. Similarly, a function name is really the starting address in memory of the code that performs the function's task. Pointers to functions can be passed to functions, returned from functions, stored in arrays, and assigned to other function pointers.

* This is the example of the function pointers, sample08f.c

void sort(int *data, int size, int (*compare)(int, int))
{  int i, j, temp;
 
   for (i=0; i < size-1; i++)
      for (j=i+1; j < size; j++)
         if ((*compare)(data[i], data[j])) {
            temp    = data[i];
            data[i] = data[j];
            data[j] = temp;
         }
}
 
void print_array(int *data, int size)
{  int i;
 
   for (i=0; i < size; i++)
      printf("%d ", data[i]);
   printf("\n");
}
 
int ascending(int a, int b)
{
   return b < a;
}
 
int descending(int a, int b)
{
   return b > a;
}
 
main ()
{  int arr[] = {5,4,3,2,1,6,7,8,9,0};
   int size;
 
   size = sizeof(arr)/sizeof(arr[0]);
 
   printf("Original\n");
   print_array(arr, size);
 
   printf("Ascending Sort\n");
   sort(arr, size, ascending);
   print_array(arr, size);
 
   printf("Descending Sort\n");
   sort(arr, size, descending);
   print_array(arr, size);
}
Dynamic Memory Allocation

The memory allocation we have seen so far (i.e. variable declaration) is static and its size cannot be changed or altered during the program execution. Look at this old example, sample07a.c in Chapter 6. We used the fixed size array to store the numbers entered by a user and then later on we were printing the value of sum once all the data were read in. Since we used the array of size 100, we can't enter more than 100 numbers. Nonetheless, if we want to be able to enter more than 100 number, we then have to change to size of the array and make sure its size must be bigger than (or at least equal to) the number of incoming data. And we need to recompile the program once we change the array size.

Dynamic memory allocation gives us the ability for a program to obtain more memory space at execution time to hold new data, and to release space no longer needed.

* Check out this example of Dynamic memory allocation, sample11a.c.

#include <stdio.h>
 
main ()
{  int *data;
   int n_data, cnt=0;
   int i, sum;
 
   printf("Enter the number of data: ");
   scanf("%d", &n_data);
 
   data = (int *)malloc(n_data*sizeof(int));
 
   while (cnt < n_data) {
      printf("Enter data: ");
      scanf("%d",&data[cnt]);       /* &data[cnt] <--> data+cnt */
      cnt++;
   }
   for (i=sum=0; i < cnt; i++) {
      sum += data[i];
      printf("Data element #%d is %d\n", i, data[i]);
   }
   printf ("Sum = %d, Mean = %.2f\n", sum, sum/(float)cnt);
}
1. malloc () and free ()

Functions malloc () and free (), and operator sizeof (), are essential to dynamic memory allocation. Function malloc () takes the number of bytes to be allocated as an argument, and returns a pointer of type void * (pointer to void) to the allocated memory. A void * pointer may be assigned to a variable of any pointer type. Function malloc () is normally used with the sizeof () operator. For example, the statement

data = (int *) malloc (100*sizeof (int));
evaluates sizeof (int) to determine the size in bytes of an int data type, allocates a new area in memory of 100*sizeof (int) bytes, and stores a pointer to the allocated memory in variable data. If no memory is available, malloc () returns a NULL pointer.

Function free () deallocates memory -- i.e. the memory is returned to the system so that the memory can be reallocated in the future. To free memory dynamically allocated by the preceding malloc () call, use the statement

free (data);