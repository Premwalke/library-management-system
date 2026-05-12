#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;

    void addBook()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;
    }

    void displayBook()
    {
        cout << "\nBook ID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;

        if (issued)
            cout << "\nStatus: Issued";
        else
            cout << "\nStatus: Available";

        cout << "\n----------------------";
    }
};

class Member
{
public:
    int memberId;
    string memberName;

    void addMember()
    {
        cout << "Enter Member ID: ";
        cin >> memberId;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, memberName);
    }

    void displayMember()
    {
        cout << "\nMember ID: " << memberId;
        cout << "\nMember Name: " << memberName;
    }
};

int main()
{
    Book books[100];
    Member members[50];

    int bookCount = 0, memberCount = 0;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book by Title";
        cout << "\n4. Search Book by Author";
        cout << "\n5. Add Member";
        cout << "\n6. Issue Book";
        cout << "\n7. Return Book";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
            {
                books[bookCount].addBook();
                bookCount++;
                cout << "\nBook Added Successfully!";
                break;
            }

            case 2:
            {
                if(bookCount == 0)
                {
                    cout << "\nNo Books Available!";
                }
                else
                {
                    for(int i = 0; i < bookCount; i++)
                    {
                        books[i].displayBook();
                    }
                }
                break;
            }

            case 3:
            {
                string searchTitle;
                bool found = false;

                cout << "Enter Book Title: ";
                getline(cin, searchTitle);

                for(int i = 0; i < bookCount; i++)
                {
                    if(books[i].title == searchTitle)
                    {
                        books[i].displayBook();
                        found = true;
                    }
                }

                if(!found)
                    cout << "\nBook Not Found!";

                break;
            }

            case 4:
            {
                string searchAuthor;
                bool found = false;

                cout << "Enter Author Name: ";
                getline(cin, searchAuthor);

                for(int i = 0; i < bookCount; i++)
                {
                    if(books[i].author == searchAuthor)
                    {
                        books[i].displayBook();
                        found = true;
                    }
                }

                if(!found)
                    cout << "\nBook Not Found!";

                break;
            }

            case 5:
            {
                members[memberCount].addMember();
                memberCount++;
                cout << "\nMember Added Successfully!";
                break;
            }

            case 6:
            {
                int bookId;
                cout << "Enter Book ID to Issue: ";
                cin >> bookId;

                bool found = false;

                for(int i = 0; i < bookCount; i++)
                {
                    if(books[i].id == bookId)
                    {
                        found = true;

                        if(!books[i].issued)
                        {
                            books[i].issued = true;
                            cout << "\nBook Issued Successfully!";
                        }
                        else
                        {
                            cout << "\nBook Already Issued!";
                        }
                    }
                }

                if(!found)
                    cout << "\nBook Not Found!";

                break;
            }

            case 7:
            {
                int bookId;
                cout << "Enter Book ID to Return: ";
                cin >> bookId;

                bool found = false;

                for(int i = 0; i < bookCount; i++)
                {
                    if(books[i].id == bookId)
                    {
                        found = true;

                        if(books[i].issued)
                        {
                            books[i].issued = false;
                            cout << "\nBook Returned Successfully!";
                        }
                        else
                        {
                            cout << "\nBook Was Not Issued!";
                        }
                    }
                }

                if(!found)
                    cout << "\nBook Not Found!";

                break;
            }

            case 8:
            {
                cout << "\nExiting Program...";
                break;
            }

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 8);

    return 0;
}