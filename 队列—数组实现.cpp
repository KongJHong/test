//数组实现队列
template<typename TYPE>
class My_Queue 
{
public:
	My_Queue(int queue_size)
			:front(0)
			,rear(0)
			,size(0)
			,capacity(queue_size)
	{
		my_queue = new TYPE[queue_size];
	}

	~My_Queue()
	{
		delete[] my_queue;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	bool isFull()
	{
		return size == capacity;
	}

	//入队函数
	void EnQueue(TYPE x)
	{
		if (isFull())
		{
			cout << "已经满了" << endl;
			return;
		}
		cout << x << "入列" << endl;
		my_queue[rear++] = x;
		rear = rear % capacity;
		++size;
	}

	//出队函数
	void DeQueue()
	{
		if (isEmpty())
		{
			cout << "队列已空" << endl;
			return;
		}
		cout << my_queue[front] << "出列" << endl;
		front = (++front) % capacity;
		--size;
	}

	void showData()
	{
		int i = front;
		int tmp = size;
		while (tmp != 0)
		{
			cout << my_queue[i] << " ---- ";
			i = (++i) % capacity;
			tmp--;
		}
		cout << endl;
	}


private:

	TYPE *my_queue;   
	int rear;         //队列尾位置
	int front;        //队列头位置
	int capacity;     //队列最大容量
	int size;         //队列中对象的数目
};



int main()
{
	
	My_Queue<int> que(3);
	que.EnQueue(55);
	que.EnQueue(2);
	que.EnQueue(3);

	que.showData();

	que.DeQueue();
	que.DeQueue();
	que.DeQueue();
	system("pause");
    return 0;
}