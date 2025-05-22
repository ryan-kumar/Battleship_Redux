# MP Battleships Prompt

[Canva Link](https://www.canva.com/design/DAGViJsW9oI/dAmLU3B1iUO4Q_RAevGGzQ/edit?utm_content=DAGViJsW9oI&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)

## Learning Objectives and Outcomes

- **Practice implementing and manipulating doubly linked lists** for dynamic data structures.
- Gain experience with **memory management**, including creating and deleting nodes.
- Work with **2D vectors and pointers** to represent and manage complex game states.
- Apply **maps** for efficient data lookup and association.
- Use **conditional logic** to handle game states (e.g., tracking hits, misses, and sunk ships).
- Develop **modular code** by dividing the game logic into clear, reusable functions.
- Strengthen **debugging skills** for data structures and real-time updates.

## Grading

- **Due Date:** Shown in the yellow box at the top of this page.
- **Submission Policy:** Unlimited penalty-free submission attempts.
- **Scoring:** 
  - Correctly pass ALL test cases to earn **100 points**.
  - Points prorated based on the percentage of test cases passed.

## Background

Ahoy captain! You’ve been tasked with testing your coding skills in the high seas to build a game engine for **Battleship**. Your mission is to:

- Allow ships to be placed on the board.
- Track the state of each ship as it takes hits.
- Display the board as ship sections are destroyed.

This project focuses on **linked lists** and **memory management**.

---

## Assignment

### Part 1: The Game Board

The game board is visualized as a grid of cells, with each cell having one of the following states:

- `"S"`: Segment of a ship that is intact.
- `"O"`: Segment of a ship that has been hit.
- `"X"`: Missed attack (empty cell targeted).
- `"."`: Open water (empty cell not yet targeted).

The board is implemented as a **2D vector of pointers to Node objects**. Each Node represents a ship segment, linked via `next` and `prev` pointers to form a **doubly linked list** for each ship.

### Part 2: Node Representation

Each Node includes:

- **Position:** A pair of integers representing the coordinates on the board.
- **Next:** Pointer to the next node in the linked list.
- **Prev:** Pointer to the previous node in the linked list.

### Part 3: Ship Representation

The **Ship class** manages a pointer to the head of its linked list. Key behaviors:

- When a segment is hit, its node is removed from the list.
- A ship is **sunk** when all its nodes are removed.
- The game ends when all ships are sunk.

#### Example

- Initialize a **5x5 board**.
- Place a ship at `(1,1)`, `(1,2)`, and `(1,3)`:

Initial Linked List Structure:
```
(1,1) <-> (1,2) <-> (1,3)
```

Initial Board Visualization:
```
. . . . .
S S S . .
. . . . .
. . . . .
. . . . .
```

---

### Part 4: Attacking the Ship

**Attack Process:**

1. Attack `(1,1)`:
   - Segment `(1,1)` is hit; node removed from the linked list.
   - Board updates to display `"O"` at `(1,1)`.

   Board:
   ```
   . . . . .
   O S S . .
   . . . . .
   . . . . .
   . . . . .
   ```

2. Attack `(1,2)`:
   - Segment `(1,2)` is hit; node removed.
   - Board displays `"O"` at `(1,2)`.

   Board:
   ```
   . . . . .
   O O S . .
   . . . . .
   . . . . .
   . . . . .
   ```

3. Attack `(1,3)`:
   - Segment `(1,3)` is hit; node removed.
   - Ship is sunk. Game state updates to remove the ship.

   Final Board:
   ```
   . . . . .
   O O O . .
   . . . . .
   . . . . .
   . . . . .
   ```

---

### Part 5: Game Play Logic

1. **Placing Ships:** 
   - Ships are added as **doubly linked lists of nodes** at specified coordinates.
   - Positions are stored in a `positionToShipMap` for quick lookup.

2. **Attacking:** 
   - Check if the position contains a ship node.
   - If hit, remove the node and update the board to `"O"`.
   - If the ship has no remaining nodes, it is sunk.

3. **End of Game:** 
   - Game continues until all ships are sunk.
   - When the set of ships is empty, the game ends.

---

## Running Your Program

**Targets:**

- TBD

**Deliverables:**

- TBD
