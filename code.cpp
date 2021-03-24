#include <iostream>
#include <vector>
#include <string>

class Data{
public:
    friend Data* add(const bool*);
    friend int selection(Data** people, bool* token);
    friend void compare_main(Data *input1, Data *input2);
    void print(const bool*);
    void edit(const bool*);

    Data() : grades(5,0) {};

private:
    std::vector<int> grades;
    std::string name;
};

Data* add(const bool*);
int selection(Data**, bool*);
void compare_main(Data *input1, Data *input2);
int compare_sub(const int, const int);


int main() {
    Data* people[10] = {nullptr};
    int option = 0, buffer = 0;
    int compare_buffer = 0, compare_buffer2 = 0;
    bool token = false;

    do {
        std::cout << "Please type your command" << std::endl
                  << "1.add  2.edit  3.print  4. delete  5.compare_main  0.exit" << std::endl;
        std::cin >> option;

        switch (option) {
            case 1: {
                buffer = selection(&people[0], &token);
                if (token == 1 || buffer == -1) break; //input error

                people[buffer] = add(&token);
                break;
            }
            case 2:{
                buffer = selection(&people[0], &token);
                if (token == 0 || buffer == -1) break; //input error

                people[buffer]->edit(&token);
                break;

            }
            case 3: {
                buffer = selection(&people[0], &token);
                if (token == 0 || buffer == -1) break; //input error

                people[buffer]->print(&token);
                break;
            }
            case 4: {
                buffer = selection(&people[0], &token);
                if (token == 0 || buffer == -1) break; //input error

                delete people[buffer];
                people[buffer] = nullptr;
                break;
            }
            case 5: {
                compare_buffer = selection(&people[0], &token);
                if(token == 0 || compare_buffer == -1) break; //input error
                compare_buffer2 = selection(&people[0], &token);
                if (token == 0 || compare_buffer2 == -1) break; //input error

                compare_main(people[compare_buffer], people[compare_buffer2]);
                break;
            }
            case 0:
            {
                std::cout << "Goodbye." << std::endl;
                break;
            }
            default:
            {
                std::cout << "Sorry, input failure." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
    }while(option != 0);
    return 0;
}

int selection(Data** people, bool* token)
{
    std::cout << "Please choose which to use." << std::endl;
    for(int i = 0;i < 10;i++)
    {
        if(people[i] == nullptr)
            std::cout << i+1 << ":Empty" << std::endl;
        else
            std::cout << i+1 << ":" << people[i]->name << std::endl;
    }
    int number = 0;
    std::cin >> number;
    if(std::cin.fail() == 1)
    {
        std::cout << "Sorry, input failure." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -1;
    }
    if(people[number-1] == nullptr)
        *token = false;
    else
        *token = true;
    return number-1;
}

Data* add(const bool* token)
{
    if((*token))
    {
        std::cout << "Sorry, this space is used." << std::endl;
        return nullptr;
    }

    Data* buffer = new Data();

    std::cout << "Please type your grade(Chinese, English, Math, Society, Science) and name" << std::endl;
    for(int i = 0; i < 5;i++)
    {
        std::cin >> buffer->grades[i];
    }
    std::cin >> buffer->name;

    std::cout << "Complete" << std::endl;
    return buffer;
}

void Data::edit(const bool* token)
{
    if(!(*token))
    {
        std::cout << "Sorry, this space is empty." << std::endl;
        return ;
    }
    int choice = 0, grade = 0;
    do {
        std::cout << "Type subject and grade.(use number)" << std::endl;
        std::cout << "1.Chinese / 2.Math / 3.Society / 4.Science / 5.English / 0.exit" << std::endl;

        std::cin >> choice;
        if(choice == 0)
        {
            std::cout << "Leaving..." << std::endl;
            break;
        }

        std::cin >> grade;
        if (std::cin.fail())
        {
            std::cout << "Sorry, input failure";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
            (this -> grades)[choice-1] = grade;

    }while(choice != 0);


}

void Data::print(const bool* token)
{
    if(!(*token))
    {
        std::cout << "Sorry, this space is empty." << std::endl;
        return ;
    }

    int sum = 0;
    for(auto it : this->grades)
        sum += it;

    std::cout << "Name: " << this->name << std::endl
              << "Chinese: " << this->grades[0] << std::endl
              << "English: " << this->grades[1] << std::endl
              << "Math: " << this->grades[2] << std::endl
              << "Society: " << this->grades[3] << std::endl
              << "Science: " << this->grades[4] << std::endl
              << "Total grade: " << sum << std::endl;
}

void compare_main(Data* input1, Data* input2)
{
    int option = 1;
    int result = 0; // -1 -> input1 win, 0 -> equal, 1 -> input2 win
    std::cout << "Please select the option to compare_main(by order)." << std::endl;
    std::cout << "1.Chinese  2.English  3.Math  4.Society  5.Science\n"
              << "6.Ch+En+Ma+Sc  7.Ch+En+Ma  8.Ch+En+So 9.Ch+En+Ma+So\n"
              << "0.end symbol\n";
    while(option != 0)
    {
        std::cin >> option;
        if(option == 0 || std::cin.fail())
        {
            if(option == 0)
                std::cout << "End operation." << std::endl;
            else
                std::cout << "Your input is incorrect, operation ended." << std::endl;

            std::cin.clear();
            std::cin.ignore(10000, '\n');
            option = 0;
            continue;
        }

        switch(option)
        {
            case 1: //chinese
                result = compare_sub(input1->grades[0], input2->grades[0]);
                break;
            case 2: //english
                result = compare_sub(input1->grades[1], input2->grades[1]);
                break;
            case 3: //math
                result = compare_sub(input1->grades[2], input2->grades[2]);
                break;
            case 4: //society
                result = compare_sub(input1->grades[3], input2->grades[3]);
                break;
            case 5: //science
                result = compare_sub(input1->grades[4], input2->grades[4]);
                break;
            case 6: //Ch+En+Ma+Sc
                result = compare_sub(input1->grades[0]+input1->grades[1]+input1->grades[2]+input1->grades[4], input2->grades[0]+input2->grades[1]+input2->grades[2]+input2->grades[4]);
                break;
            case 7: //Ch+En+Ma
                result = compare_sub(input1->grades[0]+input1->grades[1]+input1->grades[2], input2->grades[0]+input2->grades[1]+input2->grades[2]);
                break;
            case 8: //Ch+En+So
                result = compare_sub(input1->grades[0]+input1->grades[1]+input1->grades[3], input2->grades[0]+input2->grades[1]+input2->grades[3]);
                break;
            case 9: //Ch+En+Ma+So
                result = compare_sub(input1->grades[0]+input1->grades[1]+input1->grades[2]+input1->grades[3], input2->grades[0]+input2->grades[1]+input2->grades[2]+input2->grades[3]);
                break;
        }


        if(result == 0)
            std::cout << "Equal." << std::endl;
        else if(result == -1)
            std::cout << input1->name << " wins." << std::endl;
        else if(result == 1)
            std::cout << input2->name << " wins." << std::endl;

        result = 0;
    }
}

int compare_sub(const int input_a, const int input_b)
{
    if(input_a == input_b) return 0;

    return (input_a > input_b) ? -1 : 1;
}
