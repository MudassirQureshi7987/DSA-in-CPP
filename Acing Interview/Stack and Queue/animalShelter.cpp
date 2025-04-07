#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Animal {
public:
    string name;
    string type;
    int time;

    Animal(string n, string t, int ts) {
        name = n;
        type = t;
        time = ts;
    }
};

class AnimalShelter {
private:
    queue<Animal> dogs;
    queue<Animal> cats;
    int timestamp;

public:
    AnimalShelter() {
        timestamp = 0;
    }

    void enqueue(string name, string type) {
        Animal a(name,type,timestamp++);

        if(a.type == "dog")
        {
            dogs.push(a);
        }
        else if(a.type == "cat")
        {
            cats.push(a);
        }
        else
        {
            cout<<"Invalid type"<<endl;
        }
    }

    string dequeueAny() {
        if(dogs.empty() && cats.empty())
        {
            return "No animals available";
        }

        if(cats.empty())
        {
            return dequeueDog();
        }

        if(dogs.empty())
        {
            return dequeueCat();
        }

        if(dogs.front().time < cats.front().time)
        {
            return  dequeueDog();
        }
        else{
            return dequeueCat();
        }
    }

    string dequeueDog() {
        if(dogs.empty())
        {
            return "No dogs available";
        }

        string name = dogs.front().name;
        dogs.pop();

        return name;
    }

    string dequeueCat() {
        if(cats.empty())
        {
            return "No cats available";
        }

        string name = cats.front().name;
        cats.pop();

        return name;
    }
};

int main() {
    AnimalShelter shelter;

    // 🧪 Add test cases here
    // shelter.enqueue("Bruno", "dog");
    // cout << shelter.dequeueAny() << endl;

    return 0;
}
