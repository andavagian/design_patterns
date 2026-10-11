# Composite Pattern

> Compose objects into **tree structures** and let clients treat individual objects and groups of objects **uniformly**.

## Before

In `before.cpp`, `File` and `Folder` are unrelated classes.

`Folder` keeps two separate lists (`files` and `subFolders`) and needs different code for each of them.

## After

In `after.cpp`:

| Role | Class |
|---|---|
| Component | `FileSystemItem` |
| Leaf | `File` |
| Composite | `Folder` (contains any `FileSystemItem`) |

Both `File` and `Folder` implement `getSize()` and `print()`. A folder simply asks its children, and the children can be files **or** other folders.

```text
root/
  Documents/
    cv.pdf
    notes.txt
  Projects/
    main.cpp
    Makefile
  photo.png
```
