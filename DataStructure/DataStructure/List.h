#pragma once





template <typename T> class List
{
private:
	template <typename T> struct ListNode
	{
	public:
		T data;
		struct ListNode *ListNextNode;
	};
	struct ListNode *ListHeadNode;
	struct ListNode *ListEndNode;
public:
	List();
	~List();

	void insert(_In_ T data);
	void append(_In_ T data);
	void clear();
	bool remove(_In_ T data);
	T indexof(_In_ T data);
	T operator [] (_In_ int index);
	
};

