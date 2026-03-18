#include <iostream>
#include <string>

template <typename T>
class Inventory
{
public:
	//생성자
	Inventory(int capacity = 10)
	{
		capacity_ = capacity;
		if (capacity_ <= 0)
		{
			capacity_ = 1;
		}
		pItems_ = new T[capacity_];
	}

	//소멸자
	~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}

	void AddItem(const T& item)
	{
		if (size_ < capacity_)
		{
			pItems_[size_] = item;
			++size_;
		}
		else
		{
			std::cout << "인벤토리가 꽉 찼습니다!" << std::endl;
		}
	}

	void RemoveLastItem()
	{
		if (size_ > 0)
		{
			--size_;
		}
		else
		{
			std::cout << "인벤토리가 비어있습니다" << std::endl;
		}
	}

	int GetSize() const
	{
		return size_;
	}

	int GetCapacity() const
	{
		return capacity_;
	}

	void PrintAllItems() const
	{
		for (int i = 0; i < size_; i++)
		{
			pItems_ [i].PrintInfo();
		}
		std::cout << std::endl;
	}


private:
	T* pItems_ = new T[capacity_];
	int capacity_ = 10;
	int size_ = 0;
};

class Item
{
public:
	Item(std::string name = "", int price = 0)
	{ 
		name_ = name;
		price_ = price;
	}

	void PrintInfo() const
	{
		std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << std::endl;
	}

private:
	std::string name_;
	int price_;

};

int main(void)
{	
	std::string inItemName;
	int inItemPrice;
	int menu;
	Inventory < Item > ItemInven;
	while(true)
	{
		std::cout << "1. 아이템 넣기 / 2. 아이템 빼기 / 3. 인벤토리 현재 물량 / 4. 아이템 종류 확인" << std::endl;
		std::cout << ">> 메뉴 번호 입력: ";
		std::cin >> menu;
		std::cin.ignore(LLONG_MAX, '\n');
		switch (menu)
		{
		case 1:
			std::cout << ">> 아이템 이름과 가격 입력: ";
			std::cin >> inItemName >> inItemPrice;
			std::cin.ignore(LLONG_MAX, '\n');
			std::cout << "아이템 1개를 추가합니다..." << std::endl;
			ItemInven.AddItem(Item(inItemName, inItemPrice));
			break;

		case 2:
			std::cout << "아이템 1개를 제거합니다..." << std::endl;
			ItemInven.RemoveLastItem();
			break;

		case 3:
			std::cout << ItemInven.GetSize() << " / " << ItemInven.GetCapacity() << std::endl;
			break;

		case 4:
			std::cout << "▼ 현재 아이템 목록" << std::endl;
			ItemInven.PrintAllItems();
			break;
		}
	}

	return 0;
}