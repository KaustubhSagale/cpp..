#include <iostream>
#include <string.h>
using namespace std;

struct student
{
    char name[25];
    int roll_no;
    float sgpa;
} s[20];

void input(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for student no : " << i + 1 << "\n";
        cout << "Name : ";
        cin >> s[i].name;
        cout << "Roll No. : ";
        cin >> s[i].roll_no;
        cout << "SGPA : ";
        cin >> s[i].sgpa;
        cout << endl;
    }
}

void display(int n)
{
    cout << " \nSR.no \tName \tRoll No. \tSGPA \n";
    cout << "..................................................\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << i + 1;
        cout << "\t" << s[i].name;
        cout << "\t"
             << "\t" << s[i].roll_no;
        cout << "\t" << s[i].sgpa;
    }
    cout << endl;
}

void insertionsort(int n){
 struct student present ;
    int i, j;
 
 for(i=1; i<n; i++){
  present = s[i];
  j=i-1 ;
  
  while (j>=0 && strcmp(s[j].name, present.name) > 0 ){
  
   s[j+1] = s[j] ;
   j-- ;
  }
  s[j+1] = present ;
 }

}

void linearsearch(int n)
{
    float key;
    cout << "Enter SGPA you want to search ";
    cin >> key;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (key == s[i].sgpa)
        {
            flag = 1;
            cout << "Name of student : " << s[i].name << endl;
            cout << "Roll No. of student : " << s[i].roll_no << endl;
            cout << "SGPA of student : " << s[i].sgpa << endl;
            cout << "\n";
        }
    }
    if (flag == 0)
    {
        cout << " Not Found " << endl;
    }
}

void binarysearch(int n)
{
    int low = 0;
    n -= 1;
    char Name[15];
    cout << "Enter Name you want to search ";
    cin >> Name;
    int flag = 0;
    while (low <= n)
    {
        int mid = (low + n) / 2;
        int comp = strcmp(Name, s[mid].name);
        if (comp == 0)
        {
            flag = 1;
            cout << "Name of student : " << s[mid].name << endl;
            cout << "Roll No. of student : " << s[mid].roll_no << endl;
            cout << "SGPA of student : " << s[mid].sgpa << endl;
            return;
        }
        else if (comp > 0)
        {
            low = mid + 1;
        }
        else
        {
            n = mid - 1;
        }
    }
    if (flag == 0)
    {
        cout << "Not Found " << endl;
    }
}


void Bubble_sort(int n)
{
    float temp1;
    char temp2[10];
    int counter = 1, i, j, temp3;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - counter; j++)
        {
            if (s[j].roll_no > s[j + 1].roll_no)
            {
                temp1 = s[j].sgpa;
                strcpy(temp2, s[j].name);
                temp3 = s[j].roll_no;

                s[j].sgpa = s[j + 1].sgpa;
                strcpy(s[j].name, s[j + 1].name);
                s[j].roll_no = s[j + 1].roll_no;

                s[j + 1].sgpa = temp1;
                strcpy(s[j + 1].name, temp2);
                s[j + 1].roll_no = temp3;
            }
        }
        counter++;
    }

    cout << " Sorting Completed " << endl;
}

void swap(struct student s[], int i, int j)
{

    float temp1;
    char temp2[20];
    int temp3;

    temp3 = s[j].roll_no;
    temp1 = s[j].sgpa;
    strcpy(temp2, s[j].name);

    s[j].roll_no = s[i].roll_no;
    s[j].sgpa = s[i].sgpa;
    strcpy(s[j].name, s[i].name);

    s[i].roll_no = temp3;
    s[i].sgpa = temp1;
    strcpy(s[i].name, temp2);
}


int partition(struct student s[], int low, int high)
{
    int pivot = low;
    int i = low + 1;
    int j = high;

    while (s[pivot].sgpa > s[i].sgpa || s[pivot].sgpa < s[j].sgpa)
    {
        if (s[pivot].sgpa > s[i].sgpa)
        {
            i++;
        }
        else if (s[pivot].sgpa < s[j].sgpa)
        {
            j--;
        }
    }

    if (j < i)
    {
        swap(s, j, pivot);
        return j;
    }
    else
    {
        swap(s, i, j);
        swap(s, i, pivot);
        return i;
    }
}

void quick_Sort(struct student s[], int low, int high)
{

    if (low < high)
    {
        int pos = partition(s, low, high);
        quick_Sort(s, low, pos - 1);
        quick_Sort(s, pos + 1, high);
    }
}

int main()
{

    int n, ch;
    cout << "Enter the no. of students";
    cin >> n;

    do
    {
        cout << "\n1. Accept Record \n2. display Record \n3. linear search SGPA" ;
        cout<<"\n4. Binary search Name \n5. sort Roll No. \n6. quick sort\n7. insertion sort\n8. Exit\n";
        cout << "Enter Your choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            input(n);
            break;
        case 2:
            display(n);
            break;
        case 3:
            linearsearch(n);
            break;
        case 4:
            binarysearch(n);
            break;
        case 5:
            Bubble_sort(n);
            break;
        case 6:
            quick_Sort(s, 0, n-1);
            display(10) ;
            break;
        case 7:
            insertionsort(n);
            display(n) ;
            break;
        case 8:
            cout << " You are out ";
            break;
        default:
            cout << "Invalid choice ";
            break;
        }

    } while (ch != 8);

    return 0;
}