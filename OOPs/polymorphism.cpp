/*
    Polymorphism simply means many forms

    Compile time polymorphism is also known as static polymorphism. This type of polymorphism 
    can be achieved through function overloading or operator overloading.

    a) Function overloading: When there are multiple functions in a class with the same
     name but different parameters, these functions are overloaded. The main advantage of
function overloadingis it increases the readability of the program. Functions can be
overloaded by using different numbers of arguments and by using different types of arguments. 

    b) Operator Overloading: C++ also provides options to overload operators.
     For example, we can make the operator (‘+’) for the string class to concatenate two
      strings. We know that this is the addition operator whose task is to add two operands.
       A single operator, ‘+,’ when placed between integer operands, 
    adds them and concatenates them when placed between string operands.

   Runtime polymorphism is also known as dynamic polymorphism.
    Method overriding is a way to implement runtime polymorphism.

    a) Method overriding:

Method overriding is a feature that allows you to redefine the parent class
 method in the child class based on its requirement. In other words, whatever
  methods the parent class has by default are available in the child class. But,
   sometimes, a child class may not be satisfied with parent class method implementation.
    The child class is allowed to redefine that method based on its requirement.
This process is called method overriding. 

Rules for method overriding:

    The method of the parent class and the method of the child class must have the same name.
    The method of the parent class and the method of the child class must have the same
     parameters.
    It is possible through inheritance only.

 

*/