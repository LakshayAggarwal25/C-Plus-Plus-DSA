/* How to use a user defined class inside a vector
N number of cars are given at a certain distance x,y from origin, sort them based upon their distance from the origin
Input 
Number of cars
Name of each car
Position of each car
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

class Car{
    public:
    string car_name;
    int x,y;
    Car();
    Car(string name,int x,int y){
        car_name = name;
        this->x = x;
        this->y = y;
    }
    int distance(){
        return x*x + y*y;
    }
    int length(){
        return car_name.length();
    }
};

bool compare(Car a, Car b){
    int da = a.distance();
    int db = b.distance();
    if(da==db){
        return a.length() < b.length();
    }
    return da < db;
}


int main(){
    int n;
    cin>>n;
    vector<Car> v;
    for(int i = 0 ; i< n;i++){
        int x,y;
        string name;
        cin.ignore();
        cin>>name>>x>>y;
        Car temp(name,x,y);
        v.push_back(temp);
    }

    sort(v.begin(),v.end(),compare);

    for(auto c : v){
        cout<<"Car "<<c.car_name<<"\tDistance :\t"<<c.distance()<<"\tLocation : \t("<<c.x<<", "<<c.y<<")"<<endl;
    }
    return 0;
}