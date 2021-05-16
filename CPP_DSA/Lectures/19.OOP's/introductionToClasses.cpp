#include <iostream>
using namespace std;

// defining a new data type

class Car
{
    //Access Specifiers:
    // private : data members and member functions under this will not be accessible(i.e. read or write) outside the class
    // by default all the data members and member functions are private
    float price;
    int model_no;
    string name;

public:
    // public : data members and member functions under this will be accessible outside the class

    //Contructor
    Car(){
        // cout<<"Inside Constructor"<<endl;
    }

    //Parameterised Contructor
    Car(float p, int m, string str){
        price = p;
        model_no = m;
        name = str;
    }

    Car(float p){
        price = p; 
    }

    //Here we have multiple functions with the same name this is known are function overloading, 
    //since we are overloading a constructor it is known as constructor overloading  



    // Functions used to read and write the values of the private members are known as getter and setter functions
    void set_price(float p)
    { // setter function for price
        float minimumSellingPrice = 100;
        if (p > 0)
        {
            price = p;
        }
        else
        {
            price = minimumSellingPrice;
        }
    }
    void set_modelNo(int n)
    { // setter function for model number
        model_no = n;
    }
    void set_name(string str)
    { // setter function for name
        name = str;
    }
    float get_price()
    { // getter function for price
        return price;
    }
    int get_modelNo()
    {// getter function for model Number
        return model_no;
    }
    string get_name()
    {// getter function for name
        return name;
    }

    void print(){
        cout<<"Name : "<<name<<" Model Number : "<<model_no<<" Price : "<<price<<endl;
    }    
};

int main()
{
    // Creating an object
    Car a;
    // here c is the object and Car is a data type, c will now store 3 things in the memory(i.e. price, model_no, name)
    // to find the size of a class or object of the class we can pass class name of object in sizeof function
    cout <<"Size of Car Class : " <<sizeof(Car) << endl;
    // Car class does not occupy any memory it is just symbolic thing that how much space would a object of this class will occupy

    cout <<"Size of an Object of Car class : "<< sizeof(a) << endl;
    // size of a object of a class is same as the size of class

    // Creating an Array of cars
    Car cars[10]; // Stores info about max 10 cars

    //Using Setter functions
    a.set_price(100);
    a.set_modelNo(1);
    a.set_name("BMW");

    //Using Getter functions
    cout<<"Car A : "<<endl;
    cout<<"Name : "<<a.get_name()<<" Model Number : "<<a.get_modelNo()<<" Price : "<<a.get_price()<<endl;

    //Using print Function
    cout<<"Using Print Function for Car A : "<<endl;
    a.print();

    // Calling Parameterized Constructors
    Car b(1000,2,"Audi");
    cout<<"Car b : "<<endl;
    b.print();

    //
    Car c(120);
    cout<<"Car c : "<<endl;
    c.print();
    cout<<"Since we only initialized c with a price it is taking garbage values for name and model number"<<endl;

    // Calling default Copy Constructor
    Car d(a);
    cout<<"Car d : "<<endl;
    d.print();
    
    // Another Method of calling a copy constructor
    Car e = b;
    cout<<"Car e : "<<endl;
    e.print();
}