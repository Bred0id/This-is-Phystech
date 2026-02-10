#include <iostream>
#include <cstdint>

struct Node
{
    int64_t value;
    Node *next = nullptr;
};

struct Queue
{
    Node *head = nullptr;
    Node *tail = nullptr;
    size_t size = 0;

    void Push(int64_t value)
    {
        Node *new_node = new Node;
        new_node->value = value;
        if (tail == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    int64_t Pop()
    {
        if (head == nullptr)
        {
            return -1;
        }
        Node *temp = head;
        int64_t value = head->value;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    int64_t Front() const
    {
        if (head == nullptr)
        {
            return -1;
        }
        return head->value;
    }

    bool IsEmpty() const
    {
        return size == 0;
    }

    size_t Size() const
    {
        return size;
    }

    void Clear()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
};

Queue InputCards()
{
    Queue cards;
    for (int64_t i = 0; i < 5; i++)
    {
        int64_t value = 0;
        std::cin >> value;
        cards.Push(value);
    }
    return cards;
}

int64_t Game(Queue &first_cards, Queue &second_cards)
{
    int64_t count = 0;
    while (first_cards.Size() > 0 && second_cards.Size() > 0 && count < 1000000)
    {
        int64_t first_card = first_cards.Pop();
        int64_t second_card = second_cards.Pop();
        if (first_card == 0 && second_card == 9)
        {
            first_cards.Push(first_card);
            first_cards.Push(second_card);
        }
        else if (first_card == 9 && second_card == 0)
        {
            second_cards.Push(first_card);
            second_cards.Push(second_card);
        }
        else if (first_card > second_card)
        {
            first_cards.Push(first_card);
            first_cards.Push(second_card);
        }
        else
        {
            second_cards.Push(first_card);
            second_cards.Push(second_card);
        }
        count++;
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    Queue first_cards = InputCards();
    Queue second_cards = InputCards();
    int64_t result = Game(first_cards, second_cards);
    if (result == 1000000)
    {
        std::cout << "botva";
    }
    else
    {
        if (first_cards.Size() == 0)
        {
            std::cout << "second " << result;
        }
        else
        {
            std::cout << "first " << result;
        }
    }
    first_cards.Clear();
    second_cards.Clear();
}