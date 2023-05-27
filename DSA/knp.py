

def knapsack_greedy(items, capacity):
    for item in items:
        item.append(item[1] / item[0])  # value-to-weight ratio

    items = sorted(items, key=lambda x: x[2], reverse=True)

    knapsack = []
    remaining_capacity = capacity

    for item in items:
        if item[0] <= remaining_capacity:
            knapsack.append(item)
            remaining_capacity -= item[0]

    return knapsack
