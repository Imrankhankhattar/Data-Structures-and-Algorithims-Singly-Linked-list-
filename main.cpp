#include <iostream>
#include<fstream>
using namespace std;
class Node
{
private:
    string name;
    Node *next;
public:
    Node(string x)
    {
        name=x;
        next=NULL;

    }
    void Set_name(string x)
    {
        name=x;
    }
    string Get_name()
    {
        return name;
    }
    void Set_next(Node *p)
    {
        next=p;
    }
    Node* Get_next()
    {
        return next;
    }
    void Display()
    {
        cout<<name<<endl;
    }
//distructer
    /*~Node()
    {
    cout<<"i am going to be end:  "<<name<<endl;

    }*/
};
class Link_list
{
private:
    Node *first;
public:
    Link_list()
    {
        first=NULL;
    }

    void Add_at_start(string x)
    {

        Node *temp=new Node(x);
        temp->Set_next(first);
        first=temp;

    }
    void Display()
    {
        Node *temp=first;
        if(first==NULL)
        {

            cout<<"nothing to display........."<<endl;
            return;
        }
        while(temp->Get_next()!=NULL)
        {

            cout<<temp->Get_name()<<" -> ";
            temp=temp->Get_next();


        }
        cout<<temp->Get_name()<<endl;

    }
    int Size_of_list()
    {
        int size=1;
        if (first==NULL)
        {
            size=0;
            return size;//cout<<size<<endl;
        }

        else
        {

            Node *temp=first;
            while(temp->Get_next()!=NULL)
            {

                temp=temp->Get_next();
                size++;
            }
            return size;//cout<<size<<endl;
        }
    }

    void Add_at_end(string x)
    {
        if(first==NULL)
        {
            Node *temp=new Node(x);
            temp->Set_next(first);
            first=temp;
            cout<<"Node added at end......"<<endl;
            return;

        }

        Node *atend=new Node(x);
        Node *temp=first;
        while(true)
        {
            if(temp->Get_next()==NULL)
            {
                //cout<<"ok"<<endl;
                temp->Set_next(atend);
                return;
            }
            temp=temp->Get_next();
        }
    }
    void Remove_from_start()
    {
        if(first==NULL)
        {

            cout<<"No node to delete..."<<endl;
            return;
        }
        first=first->Get_next();

    }
    void Remove_from_end()
    {
        {
            if(first==NULL)
            {

                cout<<"Add node first  to delete..."<<endl;
                return;
            }
            if(first->Get_next()==NULL)
            {

                first=NULL;
                cout<<"Node deleted..."<<endl;

                return;
            }

            //Node *end=new Node(x);
            Node *temp=first;
            while(true)
            {
                if(temp->Get_next()->Get_next()==NULL)
                {
                    //cout<<"ok"<<endl;
                    temp->Set_next(NULL);//temp->Set_next(end);
                    return;
                }
                temp=temp->Get_next();
            }
        }
    }
    void Add_at_index(int index_no,string y)
    {
        if(first==NULL&&index_no>=1)
        {
            Node *temp=new Node(y);
            temp->Set_next(first);
            first=temp;
            cout<<"Node added at index no 1..."<<endl;
            return;
        }

        int size_l=Size_of_list();
        if(size_l<index_no)
        {
            Add_at_end(y);
            cout<<"Node added at end....."<<endl;
            return;
        }
        if(size_l==index_no)
        {
            Node *index=new Node(y);
            Node *temp=first->Get_next();
            Node *temp2=first;
            int z=2;
            while(z<index_no)
        {
            //temp=first;
            temp=temp->Get_next();
            temp2=temp2->Get_next();
            z++;
        }
        temp2->Set_next(index);
        index->Set_next(temp);

        //index->Set_next(temp->Get_next()->Get_next());
        //temp->Set_next(index);
        return;

        }
        int x=2;
        Node *index=new Node(y);
        Node *temp=first;
        while(x<index_no)
        {
            //temp=first;
            temp=temp->Get_next();
            x++;
        }

        index->Set_next(temp->Get_next());
        temp->Set_next(index);

    }
    void Search_name(string name)
    {
        if(first==NULL)
        {

            cout<<"No name found"<<endl;
            return;
        }
        Node *temp=first;
        int n=1;
        while(temp->Get_next()!=NULL)
        {
            if(temp->Get_name()==name)
            {

                {
                    cout<<name<<"  found at index_no:"<<n<<endl;
                    return;
                }



            }
            n++;
            temp=temp->Get_next();

        }
        if(temp->Get_name()==name)
        {
            cout<<name<<"   found at index_no:"<<n<<endl;
            return;
        }
        else
            cout<<"NOT found"<<endl;


    }
    void Delete_name_node(string name)
    {
        if(first==NULL)
        {

            cout<<"Add node first to delete.."<<endl;
            return;
        }
        Node *temp=first;
        while(temp->Get_next()!=NULL)
        {
            if(temp->Get_next()->Get_name()==name)
            {

                temp->Set_next(temp->Get_next()->Get_next());

                // temp->Set_next(NULL);

                return;
            }
            temp=temp->Get_next();
        }
        if(temp->Get_name()==name)
        {
            temp->Set_next(NULL);
            return;
        }
        else
            cout<<"Name not found at any node.."<<endl;

    }



    void Remove_at_index(int index_no)
    {

        int size_l=Size_of_list();

        if(first==NULL)
        {

            cout<<"Add node first to delete..."<<endl;
            return;
        }
        if(index_no<=0||size_l<index_no)
        {
            cout<<"Node number does not exists.Enter valid node number..."<<endl;
            return;
        }
        if(size_l==index_no)
        {
            //Node *index=new Node(y);
            Node *temp=first->Get_next();
            Node *temp2=first;
            int z=2;
            while(z<index_no)
        {
            //temp=first;
            temp=temp->Get_next();
            temp2=temp2->Get_next();
            z++;
        }
          temp2->Set_next(NULL);
          return;}



        int x=2;
        //Node *index=new Node(y);

        Node *temp=first;
        while(temp->Get_next()!=NULL)
        {
            if(index_no==x)
            {
                //temp=first;
                temp->Set_next(temp->Get_next()->Get_next());

            }
            temp=temp->Get_next();
            x++;
        }
        cout<<"Node number does not exists..... "<<endl;
    }
    void Reverse_display()
    {
        Node *temp=first;
        if(first==NULL)
        {
            cout<<"nothing to display........."<<endl;
            return;
        }
        int size_list=Size_of_list();
        // cout<<size_list<<endl;
        string Array[size_list]= {"0"};
        for(int i=1; i<=size_list; i++)
        {
            Array[i]=temp->Get_name();
//        cout<<Array[i]<<endl;
            temp=temp->Get_next();
        }
        // Array[size_list]=temp->Get_name();
        for(int j=size_list; j>=1; j--)
        {
            cout<<Array[j]<<endl;

        }
    }
void automator()
    {
        ifstream file;
        file.open("Link_list.txt");
        string ch,b;
        int no;
        while(!file.eof())
        {
            file>>ch;
       if(ch=="AAS")
        {
            file>>b;
            Add_at_start(b);
        }
        if(ch=="AAE")
        {
            file>>b;
            Add_at_end(b);
        }
        if(ch=="ADD")
        {
            file>>b;
            file>>no;
            Add_at_index(no,b);
        }
        if(ch=="REM")
        {
            file>>b;
           Delete_name_node(b);
        }
        if(ch=="RAI")
        {
            file>>no;
           Remove_at_index(no);
        }
        if(ch=="RAS")
        {
            Remove_from_start();
        }
        if(ch=="RAE")
        {
            Remove_from_end();
        }
        if(ch=="DIS")
        {
            Display();
        }
        if(ch=="DIR")
        {
            Reverse_display();
        }
    }
}

};
int main()
{
    Link_list obj;
    obj.automator();

 //   obj.automator();
   /* string choice;
    do
    {
        int number;
        string name;
        cout<<"\t\t"<<"***********Linked_list Menu************"<<"\t\t\t"<<endl;
        cout<<"\t\t\t"<<"Press 1 for: Display"<<endl<<"\t\t\t"<<"Press 2 :for Add_at_start"<<endl;
        cout<<"\t\t\t"<< "Press 3 for: Size_of_list "<<endl<<"\t\t\t"<<"Press 4 for: Add_at_end "<<endl<<"\t\t\t"<<"Press 5 for: Remove_from_end"<<endl;
        cout<<"\t\t\t"<<"Press 6 for: Add_at_index"<<endl<<"\t\t\t"<<"Press 7 for: Search_name"<<endl<<"\t\t\t"<<"Press 8 for: Delete_name_node"<<endl;
        cout<<"\t\t\t"<<"Press 9 for: Remove_at_index"<<endl<<"\t\t\t"<<"Press 10 for: Remove_from_start"<<endl<<"\t\t\t"<<"Press 11 for: Reverse_display"<<endl;
                cout<<"\t\t*********************************************\t\t\t"<<endl;

        cin>>number;


        switch (number)
        {
        case  1:
            obj.Display();
            break;
        case  2:
            cout <<"Enter name for node:"<<endl;
            cin>>name;
            obj.Add_at_start(name);
            break;
        case 3:
            int x;
            x=obj.Size_of_list();
            cout<<x<<endl;
            break;
        case 4:
            cout <<"Enter name for node:"<<endl;
            cin>>name;
            obj.Add_at_end(name);
            break;
        case 5:
            obj.Remove_from_end();
            break;
        case 6:
            cout <<"Enter name for node:"<<endl;
            cin>>name;
            int index;
            cout<<"Enter index no:"<<endl;
            cin>>index;
            obj.Add_at_index(index,name);
            break;
        case 7:
            cout <<"Enter name to search:"<<endl;
            cin>>name;
            obj.Search_name(name);
            break;
        case 8:
            cout <<"Enter name for deleting specified node:"<<endl;
            cin>>name;
            obj.Delete_name_node(name);
            break;
        case 9:
            int ind;
            cout <<"Enter index_no for deleting node:"<<endl;
            cin>>ind;
            obj.Remove_at_index(ind);
            break;
        case 10:
            obj.Remove_from_start();
            break;
        case 11:
            obj.Reverse_display();
            break;
        default:
            cout << "Error! operator is not correct";
            break;
        }
        cout<<"   Press ANY KEY to continue else NO..."<<endl;
        cin>>choice;
    }
    while(choice!="NO)"||"no");//*/
    return 0;
}

