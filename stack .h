#define MAX_SIZE 100

class stack {
    
    private:
        int element[MAX_SIZE];
        int top;
    
    public:
        stack();
        ~stack();
        void push(int element);
        int pop();
      
        
};