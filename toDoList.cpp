#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;
// Task Class That Denote Each Individual Task
class Task{
    int taskId;
    string taskName;
    string taskDesc;
    bool completed;
    public:
    Task(int id, const string& taskName, const string& taskDesc) : taskId(id), taskName(taskName), taskDesc(taskDesc), completed(false){}
   int getId() const{
    return taskId;
   }
   string getName() const{
    return taskName;
   }
   string getDescription() const{
    return taskDesc;
   }
   bool isCompleted() const{
    return completed;
   }
   void markCompleted(){
    completed=true;
    return;
   }
   void displayTask(){
    cout<<"Task Id : "<<taskId<<endl;
    cout<<"Task Name : "<<taskName<<endl;
    cout<<"Task Desc : "<<taskDesc<<endl;
    cout<<"Task Status : "<<(completed? "Completed" : "Pending")<<endl;
    cout<<"-----------------------------------------------------------------\n";
   }
} ;

// ToDoListManager Class That Manage Task Realted Operation 
 class ToDoListManager{
    vector<Task> tasks;
    int nextId;
    public: ToDoListManager(): nextId(1){}

    // Creating Add Task Func 
    void addtask(const string& taskName, const string& taskDesc){
        Task newTask(nextId++,taskName,taskDesc);
        tasks.push_back(newTask);
        cout<<"Task Get Added Successfully !! \n";
        return;
    }
   // ViewTask Func to Display Each Task
    void viewTasks(){
        if(tasks.empty()){
            cout<<"To Do List Is Empty !!! \n";
            return;
        }
        else{
            cout<<"\nTo Do List -----> \n";
            cout<<"-----------------------------------------------------------------\n";
            for( auto& task: tasks){
                task.displayTask();
            }
        }
        cout<<"-----------------------------------------------------------------\n";
        return;
    }

    // MarkTaskCompleted Func to Mark A Individual Task As Completed
    void markTaskCompleted(int taskId){
        if(tasks.empty()){
            cout<<"To Do List Is Empty !!! \n";
            return;
        }
        else{
            for(auto& task: tasks){
                if(task.getId()==taskId){
                    task.markCompleted();
                    cout<<"Task get Marked Completed Succesfully !!!\n";
                    return;
                }
            }
        }
        cout<<"No Such Task is Found !! | Please Enter Correct Task Id \n";
        return;
    }

    // RemoveTask FunC To Remove An Individual Task
    void removeTask(int taskId){
        if(tasks.empty()){
             cout<<"To Do List Is Empty !!! \n";
             return;
        }
        else{
            for(auto it= tasks.begin(); it!=tasks.end();++it){
                if(it->getId()==taskId){
                    tasks.erase(it);
                    cout<<"Task Get Removed Successfully\n";
                    return;
                }
            }
        }
         cout<<"No Such Task is Found !! | Please Enter Correct Task Id \n";
         return;
    }
 };

// DisplayMenu Func
 void DisplayOperation(){
    cout<<"\n-------To Do List Manager ----------\n";
    cout<<"Select Any Operation You Want To Perform \n";
    cout<<"1.Add Task In TO Do List\n2.View Tasks()\n3.Mark Task Completed \n4. Remove Task From To Do List\n5.Exit()\n";
    return ;
 }
 int main(){
    ToDoListManager manager;
    int choice;
    cout<<"Welcome To The To Do List !!!\n";
    do{
    DisplayOperation();
    cout<<"Enter Your Choice (1 to 5) :  ";
    while(!(cin>>choice) || choice<1 || choice>5){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>:: max(),'\n');
        cout<<"Invalid Choice !! | Please Select Operation From [1 to 5 ] : ";
    }
    cin.ignore(); // ignore newline character after choice input
    switch (choice)
    {
    case 1: { 
        string taskName, taskDesc;
        cout<<"Enter the Task Name :  ";
        getline(cin, taskName);  // Getline Used To Store A Line Or A Paragraph And Terminate After  Encountering Newlline character
        cout<<"Enter the Task Description : ";
        getline(cin,taskDesc);
        manager.addtask(taskName,taskDesc);
        break;
        }
    case 2:   manager.viewTasks();
    break;
    case 3: {
        int taskId;
        cout<<"Enter The Task Id You Want To Mark As Complete : ";
        cin>>taskId;
        manager.markTaskCompleted(taskId);
        break;
    } 
    case 4: {
        int taskId;
        cout<<"Enter The Task Id You Want To Remove From To Do List :  ";
        cin>>taskId;
        manager.removeTask(taskId);
        break;
    }
    case 5: cout<<"Exiting The Program -----> \n";
    break;
    }

 }while(choice!=5);
 cout<<"Thanks You (: !! Have A Great Day \n";
 }