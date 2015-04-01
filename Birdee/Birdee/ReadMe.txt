Array
	The access time of an array will be largely decreased if the array is a variable rather than a member or a return value. Because the when accessing the array, the compiler have to push the array pointer for GC if the array is not a varible (a varible can be static, parameter, local variable or AutoVar)
	Object arrays are much slower than int/double arrays for the same reason.

	example 1:
	dim kp as string[]= new string[10]
	function kkk() as string[]
	 return kp
	end

	dim i as int
	for i=0;i<10000000;i++
	unsafe
		kkk()[3]=null
	end
	--------------------------------------
	example 2:
	dim kp as string[]= new string[10]
	dim i as int
	for i=0;i<10000000;i++
	unsafe
		kp[3]=null
	end

	example 1 takes 1669ms, while example 2 takes only 93ms. 
	example 1 is amazingly slower than example2.

	example 3 changes the string array to an int array. Note that the three programs are doing similar things (setting an element of the array to null/0)
	example 3:
	dim kp as int[]= new int[10]
	dim i as int
	for i=0;i<10000000;i++
	unsafe
		kp[3]=0
	end
	The execution time of example 3 is 16ms, which is 100 times faster than example 1 !!!!
	 

Templates
	子泛型类的类参数要比父泛型类参数小或等于
	子泛型类的类参数个数〉=父泛型类，前几个类参数与父泛型类的参数对应
	泛型类的类参数应该是参数指定的类的子类或相等