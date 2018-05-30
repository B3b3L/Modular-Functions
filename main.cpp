#include <iostream>
#include <vector>

using namespace std;

void display_menu();
char get_selection();

// Menu function prototypes
void handle_display(const vector<int> &v);
void handle_add(vector<int> &v);
void handle_mean(const vector<int> &v);
void handle_smallest(const vector<int> &v);
void handle_largest(const vector<int> &v);
void handle_find(const vector<int> &v);
void handle_quit();
void handle_unknown();

//Prototypes for functions that work with the list to display , calculate mean etc.
void display_list(const vector<int> &v);
double calculate_mean(const vector<int> &v);
void get_smallest(const vector<int> &v);
void get_largest(const vector<int> &v);
bool find(const vector<int> &v, int target);

int main()
{
    vector <int> nrs;
    char selection{};

    do
    {
        display_menu();
        selection = get_selection();
        switch(selection)
        {
            case 'P':
                handle_display(nrs);
                break;
            case 'A':
                handle_add(nrs);
                break;
            case 'M':
                handle_mean(nrs);
                break;
            case 'S':
                handle_smallest(nrs);
                break;
            case 'L':
                handle_largest(nrs);
                break;
            case 'F':
                handle_find(nrs);
                break;
            case 'Q':
                handle_quit();
                break;
            default:
                handle_unknown();
        }

    }while(selection != 'Q');

    cout << endl;
    return 0;
}

void display_menu()
{
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Find a number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice" << endl;
}

char get_selection()
{
    char selection{};
    cin >> selection;
    return toupper(selection);
}

void handle_display(const vector<int> &v)
{
    if(v.size() == 0)
        cout << "[] list is empty" << endl;
    else
        display_list(v);
}

void display_list(const vector<int> &v)
{   cout << "[ ";
    for(auto i : v)
    {
        cout << i << " ";
    }

    cout << " ]" << endl;
}

void handle_add(vector<int> &v)
{
    int num {};
    cout << "Enter an integer to add to the list: ";
    cin >> num;
    v.push_back(num);
    cout << num << " added" << endl;

}

void handle_mean(const vector<int> &v)
{
    if(v.size() == 0)
    {
        cout << "Unable to calculate the mean - list is empty" << endl;
    }
    else
    {
        cout << "The mean is " << calculate_mean(v) << endl;
    }
}

double calculate_mean(const vector<int> &v)
{
    int mean{};
    for( auto i : v)
    {
        mean += i;
    }

    return static_cast<double>(mean) / v.size();

}

void handle_smallest(const vector<int> &v)
{
    if(v.size() == 0)
    {
        cout << "Unable to determine the smallest - list is empty" << endl;
    }
    else
    {
        get_smallest(v);
    }
}

void get_smallest(const vector<int> &v)
{
    int small = v.at(0);

    for(auto i : v)
    {
        if(i < small)
        {
            small = i;
        }
    }

    cout << "The smallest number is: " << small << endl;
}

void handle_largest(const vector<int> &v)
{
    if(v.size() == 0)
    {
        cout << "Unable to determine the largest - list is empty" << endl;
    }
    else
    {
        get_largest(v);
    }
}

void get_largest(const vector<int> &v)
{
    int num = v.at(0);

    for(auto i : v)
    {
        if(i > num)
        {
            num = i;
        }
    }

    cout << "The largest number is: " << num << endl;

}

void handle_quit()
{
    cout << "Goodbye" << endl;
}

void handle_unknown()
{
    cout << "Unknown selection - try again" << endl;
}

void handle_find(const vector<int> &v)
{
    int target{};
    cout << "Enter the number to find: ";
    cin >> target;

    if(find(v, target))
    {
        cout << target << " was found" << endl;
    }
    else
    {
        cout << target << " was not found" << endl;
    }
}


bool find(const vector<int> &v, int target)
{
    for(auto i : v)
    {
        if( i == target)
        {
            return true;
        }
    }

    return false;
}
