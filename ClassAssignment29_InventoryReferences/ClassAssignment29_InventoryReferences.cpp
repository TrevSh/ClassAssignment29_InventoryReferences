#include <iostream>
#include <string>
#include <vector>

std::string& refToElement(std::vector<std::string>& inventory, int i);

int main()
{
    std::vector<std::string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    //Displays string that the returned reference refers to
    std::cout << "Sending the returned reference to cout: \n";
    std::cout << refToElement(inventory, 0) << "\n\n";

    //assigns one ref to another--inexpensive assignment
    std::cout << "Assigning one reference to another reference. \n";
    std::string& rStr = refToElement(inventory, 1);
    std::cout << "Sending the new reference to cout: \n";
    std::cout << rStr << "\n\n";

    //copies a string object -- expensive assignment
    std::cout << "Assigning the returned reference to a string object\n";
    std::string str = refToElement(inventory, 2);
    std::cout << "Sending the new string object to cout: \n";
    std::cout << str << "\n\n";

    //altering the string object through a returned reference
    std::cout << "Altering an object through a returned reference. \n";
    rStr = "Healing Potion";
    std::cout << "Sending the altered object to cout: \n";
    std::cout << inventory[1] << "\n";

    system("pause");
    return 0;
}

//returns a reference to a string
std::string& refToElement(std::vector<std::string>& vec, int i) {
    return vec[i];
}