//Elleson Tran
//Roberts
//My Contacts
//Display, add, remove, and store contacts
//FINAL

#include <iostream>
#include <vector>

using namespace std;


struct contact{
    string name;
    string phone;
    string email;
    contact(){}
    contact(string n, string p, string e)
    {
        name=n;
        phone=p;
        email=e;
    }
};

//displays everyone in the contacts
void displayContacts(vector<contact> contacts){
  for(int x = 1; x <= contacts.size(); x++){
    cout<<endl<<"Contact "<<x;
    cout<<endl<<"Name: "<<contacts[x-1].name;
    cout<<endl<<"Phone: "<<contacts[x-1].phone;
    cout<<endl<<"Email: "<<contacts[x-1].email;
    cout<<endl<<"--------------------";
  }
}

//finds whoever you're trying to find in the contacts BINARY SEARCH
int search(vector<contact> contacts, string name){
  int low = 0;
  int high = contacts.size() - 1;
  int mid;

  while (low <= high){
    mid = (low + high) / 2; //to get the pivot point

    if (contacts[mid].name == name){//if the name is found
      return mid;//the mid is the pivot point
    }
    else if (contacts[mid].name > name)//if the name is towards the beginning of the vector
      high = mid - 1; 
    else//if the name is towards the end of the vector
      low = mid + 1;  
  }

  return -1;//if it goes through the whole vector without finding the name, returns -1
}

//adds a person to the contact list
vector<contact> addContact(vector<contact> &contacts){
  string name;
  cout<<endl<<"Name: ";
  getline(cin, name);

  string phone;
  cout<<"Phone: ";
  cin>>phone;

  string email;
  cout<<"Email: ";
  cin>>email;
  
  vector<contact> copyContacts = contacts;//copy of the vector to keep the contacts in order
  contact newPerson(name, phone, email);//the new person
  int position = 0;//the position the person is suppose to be in

  //goes through the whole contact list to find out where to put the person
  for(int x = 0; x < contacts.size(); x++){
    if(name > contacts[x].name){//if the new name goes after the name we're on, add one
      position = position + 1;
    }
  }

  contacts.resize(contacts.size() + 1); //increases the contact size by one before we start shifting people


  //shifts everything after the position by one
  for(int x = position; x < copyContacts.size(); x++){
    contacts[x + 1] = copyContacts[x];
  }

  contacts[position] = newPerson;//finally inserts the person into the correct position
  cout<<"Contact Added";

  return contacts;
}


//updates the information of a person in the contacts
vector<contact> updateContact(vector<contact> &contacts){
  string personUpdate;
  cout<<endl<<"Person to Update: ";
  getline(cin, personUpdate);

  int position = search(contacts, personUpdate);//uses helper function to find the position of the person needed to update

  if(position == -1){//if the search doesnt find anyone
    cout<<endl<<"Contact not Found";
  }
  if(position != -1){//if the search finds the person somewhere in the contacts
    string phone;
    cout<<"Phone: ";
    cin>>phone;

    string email;
    cout<<"Email: ";
    cin>>email;

    //inserts the new info into the found position of the person
    contacts[position].phone = phone;
    contacts[position].email = email;
    cout<<"Contact Updated";
  }


  return contacts;
}

//removes someone from the contacts
vector<contact> removeContact(vector<contact> &contacts){
  string personRemove;
  cout<<endl<<"Person to Remove: ";
  getline(cin, personRemove);

  int position = search(contacts, personRemove);//uses helper function to find the position of the person needed to removeContact
  
  if(position == -1){//if the search doesnt find anyone
    cout<<endl<<"Contact not Found";
  }

  if(position != -1){//if the search finds the person somewhere in the contacts
    contacts.erase(contacts.begin() + position); //uses erase method
    cout<<"Contact Removed";
  }


  return contacts;
}

//prints the menu and makes the users choice uppercase
char menu(){
  char choice;

  cout<<endl;
  cout<<endl<<"D - Display Contacts";
  cout<<endl<<"A - Add Contact";
  cout<<endl<<"U - Update Contact";
  cout<<endl<<"R- Remove Contact";
  cout<<endl<<"Q- Quit"<<endl;
  cin>>choice;

  cin.ignore();

  choice = toupper(choice);//capitalizes the users choice
  return choice;
}

int main(){


    vector<contact>mycontacts={
        contact("Bethany Petr", "240-740-1509", "Bethany_A_Petr@mcpsmd.org"),
        contact("Lindsay Roberts", "240-740-1527", "Lindsay_Roberts@mcpsmd.org"),
        contact("Paul Turner", "240-740-1527", "James_Turner@mcpsmd.org")
    };

  
  char choice;

  do{//keeps going until the user wants to quit

    choice = menu();

    if(choice == 'D'){//display
      displayContacts(mycontacts);
    }

    if(choice == 'A'){//add
      addContact(mycontacts);
    
    }
    if(choice == 'U'){//update
      updateContact(mycontacts);
    }
    if(choice == 'R'){//remove
      removeContact(mycontacts);
    }

  }while(choice!= 'Q');

}
