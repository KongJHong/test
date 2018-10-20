设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

-------------------------------------------
思路：没什么，就做个栈，尽量调函数吧，这样比较快。
但是如果纯自己写的话，要注意双栈的空间处理（删除，增加）
-------------------------------------------------------
//别人
class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        num_stack.push(x);
        if (0 == min_stack.size())
            min_stack.push(x);
        else
            min_stack.push(min(x, min_stack.top()));
    }

    void pop() {
        if (0 != num_stack.size()) num_stack.pop();
        if (0 != min_stack.size()) min_stack.pop();
    }

    int top() { return num_stack.top(); }

    int getMin() { return min_stack.top(); }

   private:
    stack<int> num_stack, min_stack;
};
----------------------------------------------
//我
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        this->up = -1;
        this->capacity = 10;
        _stack = new int[this->capacity];
    }
    
    void push(int x) {
        this->up++;
        if((this->up+1) == this->capacity)
        {
            this->capacity = (int)(this->capacity * 1.5 + 10);

            _tmpStack = new int[this->capacity]{0};
            int i = 0;
            while(i < this->up)
            {
                *(_tmpStack+i) = *(_stack+i);
                i++;
            }
            
            i = 0;
            delete _stack;
            _stack = new int[this->capacity]{0};
            
            while(i < this->up)
            {
                *(_stack+i) = *(_tmpStack+i);
                i++;
            }
            
            delete _tmpStack;
            
        }
        *(_stack + this->up) = x;
    }
    
    void pop() {
        if(this->up == -1){
            this->capacity = 0;
            return;
        }
        this->up--;
    }
    
    int top() {
        if(this->up == -1)return -1;
        return *(_stack+this->up);
    }
    
    int getMin() {
        if(this->up == -1)return -1;
        int min = *(_stack);
        int i = 1;
        while(i <= this->up){
            if(min >*(_stack+i)){
                min = *(_stack+i);
            }
            i++;
        }
        return min;
    }
    
private:
    int *_stack;
    int *_tmpStack;
    int up;
    int capacity;
};

