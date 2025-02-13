# Implement a LRU Cache

An efficient implementation of a Least Recently Used (LRU) cache that provides O(1) time complexity for both get and put operations. The LRU cache maintains a fixed size and automatically removes the least recently used items when capacity is exceeded.

## Features

- Initialize cache with custom capacity
- Get values by key with O(1) time complexity
- Put key-value pairs with O(1) time complexity
- Automatic eviction of least recently used items
- Thread-safe operations (implementation dependent)

## API Reference

### Constructor

```java
LRUCache(int capacity)
```

Initializes an LRU cache with the specified capacity.

**Parameters:**
- `capacity`: The maximum number of key-value pairs the cache can hold (must be positive)

**Example:**
```java
LRUCache cache = new LRUCache(2); // Creates a cache that can hold 2 items
```

### Methods

#### get

```java
int get(int key)
```

Retrieves the value associated with the given key. Updates the item's position as most recently used.

**Parameters:**
- `key`: The key to look up

**Returns:**
- The value associated with the key if it exists
- -1 if the key doesn't exist in the cache

**Example:**
```java
LRUCache cache = new LRUCache(2);
cache.put(1, 1);
cache.get(1);    // returns 1
cache.get(2);    // returns -1 (not found)
```

#### put

```java
void put(int key, int value)
```

Inserts or updates a key-value pair in the cache. If the key exists, updates its value and marks it as most recently used. If the key doesn't exist, adds the pair and evicts the least recently used item if the cache is at capacity.

**Parameters:**
- `key`: The key to insert or update
- `value`: The value to associate with the key

**Example:**
```java
LRUCache cache = new LRUCache(2);
cache.put(1, 1);    // cache is {1=1}
cache.put(2, 2);    // cache is {1=1, 2=2}
cache.put(3, 3);    // cache is {2=2, 3=3}, key 1 is evicted
```

## Implementation Details

The O(1) time complexity is achieved by combining two data structures:
1. A doubly-linked list to maintain the order of elements (most recent to least recent)
2. A hash map to provide O(1) access to cache nodes

## Time Complexity

- Get: O(1)
- Put: O(1)
- Space Complexity: O(capacity)

## Complete Usage Example

```java
LRUCache cache = new LRUCache(2);

// Add some items
cache.put(1, 1);          // cache is {1=1}
cache.put(2, 2);          // cache is {1=1, 2=2}
System.out.println(cache.get(1));       // returns 1
cache.put(3, 3);          // evicts key 1, cache is {2=2, 3=3}
System.out.println(cache.get(1));       // returns -1 (not found)
System.out.println(cache.get(2));       // returns 2
cache.put(4, 4);          // evicts key 2, cache is {3=3, 4=4}
System.out.println(cache.get(2));       // returns -1 (not found)
System.out.println(cache.get(3));       // returns 3
System.out.println(cache.get(4));       // returns 4
```

## Edge Cases and Error Handling

- Attempting to initialize with non-positive capacity should throw an IllegalArgumentException
- Null keys or values are not supported (implementation dependent)
- The cache maintains thread safety (implementation dependent)

## Performance Considerations

1. Memory Usage:
   - Space complexity is O(capacity)
   - Each entry requires storage for the key, value, and linked list node pointers

2. Thread Safety:
   - If thread safety is required, consider using synchronized methods or a concurrent implementation
   - Be aware that synchronization may impact performance
