# DS-LAB-PARKING
Parking Garage System
# 🅿️ Parking Garage Management System

### 📘 Overview
This **Parking Garage Management System** is a C program that simulates a small parking lot with a fixed number of slots and a waiting queue.  
It demonstrates the use of **arrays**, **stacks**, **queues**, and **linked lists** to manage vehicles efficiently — handling parking, removal, waiting queues, and maintaining a parking history.

---

## ⚙️ Features

✅ **Park a Vehicle**  
- Parks a vehicle in the next available slot.  
- If the garage is full, the vehicle is added to the **waiting queue**.

✅ **Remove a Vehicle**  
- Removes a specific vehicle by license plate.  
- Temporarily moves other cars using a **stack** to simulate real-life movement inside a single-lane garage.  
- If cars are waiting in the queue, the first one gets parked automatically.

✅ **Display Garage Status**  
- Shows all parking slots with either the vehicle plate number or “Empty.”

✅ **Display Waiting Queue**  
- Shows vehicles currently waiting to be parked.

✅ **Parking History Log**  
- Keeps a record (using a **linked list**) of all vehicles that have ever parked.

✅ **User-Friendly Menu Interface**  
- Simple console menu to interact with all system functions.

---

## 🧩 Data Structures Used

| Structure | Purpose | Implementation |
|------------|----------|----------------|
| **Array** | Stores parked cars | `garage[MAX_SLOTS][PLATE_SIZE]` |
| **Queue** | Holds waiting vehicles | Circular queue with `front`, `rear`, and `QueueCount` |
| **Stack** | Temporarily stores cars when removing a vehicle | Simulates cars being moved out |
| **Linked List** | Records all cars that have parked | Maintains historical log |

---

## 🏗️ Program Flow

1. **Main Menu** displays user options.
2. **Park Vehicle (1):**  
   - If there’s space → park it.  
   - Else → add to waiting queue.
3. **Remove Vehicle (2):**  
   - Finds the car.  
   - Uses a stack to temporarily move blocking cars.  
   - Removes the desired car and restores others.  
   - Parks the next waiting car, if any.
4. **Display Garage (3):**  
   - Shows each slot’s current state.
5. **Display Queue (4):**  
   - Prints all queued cars.
6. **Show Parking History (5):**  
   - Prints all cars that have ever parked.
7. **Exit (6):**  
   - Cleanly terminates the program.

---

## 🧠 Example Run

```
--- Parking Garage System ---
1. Park Vehicle
2. Remove Vehicle
3. Display Garage
4. Display Waiting Queue
5. Show Parking History
6. Exit
Enter choice: 1
Enter plate number: ABC123
Vehicle ABC123 has been parked at: 1

Enter choice: 1
Enter plate number: XYZ999
Vehicle XYZ999 has been parked at: 2

Enter choice: 2
Enter plate number to remove: ABC123
Removing vehicle ABC123 from slot 1
Vehicle XYZ999 restored to slot 1
```

---

## 🧾 Constants & Limits

| Constant | Description | Value |
|-----------|--------------|--------|
| `MAX_SLOTS` | Maximum parking slots | 5 |
| `MAX_QUEUE` | Maximum waiting queue length | 5 |
| `PLATE_SIZE` | Max characters in a plate number | 20 |

You can modify these constants at the top of the code to fit your simulation size.

---

## 💻 Compilation & Execution

### **Compile:**
```bash
gcc parking_garage.c -o parking_garage
```

### **Run:**
```bash
./parking_garage
```

---

## 🧹 Memory Management
- Dynamically allocated nodes in the linked list (`car` struct) store historical logs.
- No memory leaks occur since nodes are only created once per parked car (history record).

---

## 🧑‍💻 Author
**Rafid**  
📚 Course: *Discrete Mathematics*  
🏫 Department of Computer Science  

---

## 🏁 Future Enhancements
- Add timestamps for parked and removed cars.  
- Save history to a file for persistence.  
- Implement car search by plate number.  
- Use dynamic resizing for garage and queue arrays.  
