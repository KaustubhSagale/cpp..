#include<iostream>

#include<math.h>

using namespace std ;
struct node{
    char data;
    struct node *next;
    
};

class stack
{
private:
    struct node *top;
    int MAX ;
public:

     stack(int s){
        top = NULL;
        MAX = s ;
    }

    node *createNewNode(char input);
    int totalElements();
    bool isEmpty();
    bool isFull();
    void push(char input);
    char pop();
    char gettop() ;
    void Display();
   
};

node *stack ::createNewNode(char input){
    struct node *newnode;
    newnode = new struct node ;
        
    newnode->data = input ;
    newnode->next = NULL;
    return newnode;
}

bool stack :: isEmpty(){
    if(top==NULL){
        return true;
    }
    else{
        return false;
    }
}

bool stack :: isFull(){
    if(MAX == totalElements()){
        return true;
    }
    else{
        return false;
    }
}


void stack::push(char input)
{

    if(isFull()){
        cout<<"stack overflow..."<<endl ;
    }
    else{
        struct node *newnode = createNewNode(input);
        newnode->next = top;
        top = newnode ;
    }
}




char stack::pop(){

    if(isEmpty()){
        cout<<"stack in Underflow..."<<endl ;
        return 0 ;
    }else
    {
        struct node *nodeToDelete ;
        char data = top->data ;
        nodeToDelete = top ;
        top = top->next ;
        delete(nodeToDelete);
        return data ;

    }
    
}



void stack::Display()
{
    struct node *temp;
    temp = top ;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next ;
    }
    cout<<endl;
    
}

char stack::gettop(){
    return top->data ;
}

int stack :: totalElements(){
    
    int count = 0;
    struct node *temp;
    temp = top ;
    while (temp != NULL)
    {
        count++ ;
        temp = temp->next ;
    }
    return count;

}

int preference(char operand){
    
    if(operand=='^' || operand=='$'){
        return 4;
    }

    else if (operand=='*' || operand=='/'){
       return 3;
    }
    
    else if (operand=='+' || operand=='-'){
        return 2;
    }

    else if(operand=='('){
        return 1;
    }

    else {
        return -1;
    }
}

void convert_inftopost(string str)
{
    stack st(str.length());
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        char operand = str[i];
        if (operand == ' ')
        {
            continue;
        }

        else if (isalnum(operand))
        {
            result += operand;
        }

        else if(operand=='(')
        {
            st.push(operand) ;
        }

        else if (operand==')')
        {
            operand = st.pop();
            while (operand!= '(')
            {
                result += operand;
                operand = st.pop();
            }
        }
        else{
            while((!st.isEmpty()) && (preference(st.gettop())>=preference(operand))){
                result += st.pop();
            }

            st.push(operand);
            
        }

    }

    while (!st.isEmpty())
    {
        result += st.pop() ; 
    }

    cout<<result<<endl ;
    
}

void convert_inftopre(string str)
{
    stack st(str.length());
    string result;

    for (int i =(str.length()-1); i >=0; i--)
    {
        char operand = str[i];
        if (operand == ' ')
        {
            continue;
        }

        else if (isalnum(operand))
        {
            result += operand;
        }

        else if(operand=='('){
            operand = st.pop();
            while (operand!= ')')
            {
                result += operand;
                operand = st.pop();
            }
        }

        else if (operand==')'){
            st.push(operand) ;
        }

        else{
            while((!st.isEmpty()) && (preference(st.gettop())>preference(operand))){
                result += st.pop();
            }

            st.push(operand);
            
        }

    }

    while (!st.isEmpty())
    {
        result += st.pop() ; 
    }

    for(int i=(result.length()-1); i>=0; i--){
        cout<<result[i] ;
    }
    cout<<endl ;
    
}

int evaluate_prefix(string str){
    stack st(str.length()) ;
   
    for(int i=(str.length()-1); i>=0; i--){
       
        if(isalnum(str[i])){
            st.push(str[i]-'0');
        }
        else{
            
            int operator1 = st.gettop();
            st.pop() ;
            int operator2 = st.gettop();
            st.pop() ;
            
            if (str[i]=='+'){
                st.push(operator1+operator2);
            }
            else if (str[i]=='-'){
                st.push(operator1-operator2);
            }
            else if (str[i]=='*'){
                st.push(operator1*operator2);
            }
            else if (str[i]=='/'){
                st.push(operator1/operator2);
            }
            else if (str[i]=='^' || str[i]=='$'){
                int result = pow(operator1,operator2);
                st.push(result);
            }
            else if (str[i]=='%'){
                st.push(operator1%operator2);
            }
        }
    }

   
    return st.gettop() ;
}

int evaluate_postfix(string str){
    stack st(str.length()) ;
    for(int i=0; i<str.length(); i++){
        
        if(isalnum(str[i])){
            st.push(str[i]-'0');
        }
        else{
          
            int operator2 = st.gettop();
            st.pop() ;
            int operator1 = st.gettop();
            st.pop() ;
            
            if (str[i]=='+'){
                st.push(operator1+operator2);
            }
            else if (str[i]=='-'){
                st.push(operator1-operator2);
            }
            else if (str[i]=='*'){
                st.push(operator1*operator2);
            }
            else if (str[i]=='/'){
                st.push(operator1/operator2);
            }
            else if (str[i]=='^' || str[i]=='$'){
                int result = pow(operator1,operator2);
                st.push(result);
            }
            else if (str[i]=='%'){
                st.push(operator1%operator2);
            }
        }
    }
   
    return st.gettop() ;
}

int main(){

    string str ;
    int ch ;

    do
    {
        cout<<"1.Convert infix to prefix\n2.Convert infix to postfix\n3.Evaluate Prefix expression\n4.Evaluate Postfix expression\n5.Exit\nEnter the choice to perform operation - ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            cout<<"Enter infix Expression : \n" ; 
            cin>>str ;
            cout<<"Converted Prefix Expression- \n";
            convert_inftopre(str) ;
            break;

            case 2:
            cout<<"Enter infix Expression : \n" ; 
            cin>>str ;
            cout<<"Converted Postfix Expression- \n";
            convert_inftopost(str) ;
            break;

            case 3:
            cout<<"Enter Prefix Expression : \n";
            cin>>str;
            cout<<"Result : \n"<<evaluate_prefix(str)<<endl;
            break;

            case 4:
            cout<<"Enter Postfix Expression : \n";
            cin>>str;
            cout<<"Result : \n"<<evaluate_postfix(str)<<endl;
            break;

            case 5:
            cout<<"You are out\n";
            break;

            default:
            cout<<"Invalid choice\n";
            break;


        }

    } while (ch!=5);

   
    return 0;
}