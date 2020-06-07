#ifndef QueuePriorityClass
#define QueuePriorityClass

class QueuePriority
{
private:
	int* cells_;
	int* priorityMarkers_;
	int maxLength_;
	int	currentLength_;

public:
	QueuePriority(int maxLen);
	~QueuePriority();

	void add(int obj, int priority);
	int extract();
	void clear();
	bool isEmpty() const;
	bool isFull() const;
	int getCurrentLen() const;
	void print() const;

};
#endif // !QueuePriorityClass