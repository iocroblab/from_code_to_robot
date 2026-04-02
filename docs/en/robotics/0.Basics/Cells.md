

clear all;

# Cell Arrays in MATLAB

In this tutorial we will explain what MATLAB cell arrays are and how to work with them.


Please enable "Output inline" on the right side of your scroll bar.


![image_0.png](Cells_media/image_0.png)

# Create a Cell Array

A cell array is a data type that can hold different types or sizes of data in each cell.


Use curly braces { } to define cells, separating entries by commas or spaces, and rows by semicolons.


 Define a 1×3 cell array

```matlab
C = {'text', 42, [1,2,3]}
```


| |1|2|3|
|:--:|:--:|:--:|:--:|
|1|'text'|42|[1,2,3]|



Define a 2×2 cell array

```matlab
C2 = { 'pi',    pi; ...
    'matrix', [1 2;3 4] }
```


| |1|2|
|:--:|:--:|:--:|
|1|'pi'|3.1416|
|2|'matrix'|[1,2;3,4]|


# Accessing Cell Elements

Use parentheses ( ) to extract a cell (returns a cell), and curly braces { } to extract its contents.


Extract a 1×1 cell

```matlab
cell1 = C(2)
```

```matlabTextOutput
cell1 = 1x1 cell array
    {[42]}

```


Extract the content (numeric 42)

```matlab
value42 = C{2}
```

```matlabTextOutput
value42 = 42
```


Access part of the matrix inside cell


```matlab
subval = C2{2,2}(1,2)
```

```matlabTextOutput
subval = 2
```

# Modifying Cell Elements

Assign into cells with curly braces { } to overwrite contents, or with parentheses ( ) to overwrite cell itself.


Change the second cell content to a string

```matlab
C{2} = 'answer'
```


| |1|2|3|
|:--:|:--:|:--:|:--:|
|1|'text'|'answer'|[1,2,3]|



Replace entire cell with another cell

```matlab
C(3) = {ones(3)}
```


| |1|2|3|
|:--:|:--:|:--:|:--:|
|1|'text'|'answer'|[1,1,1;1,1,1;1,1,1]|



Add a new cell at the end

```matlab
C{4} = @sin
```


| |1|2|3|4|
|:--:|:--:|:--:|:--:|:--:|
|1|'text'|'answer'|[1,1,1;1,1,1;1,1,1]|@sin|


# Nested Cell Arrays

Cells can contain other cell arrays for hierarchical storage.


Create nested cell

```matlab
Cnested = { 'level1', { 'level2', { 100, 200 } } }
```


| |1|2|
|:--:|:--:|:--:|
|1|'level1'|1x2 cell|



Access deeply nested value 200

```matlab
deep200 = Cnested{2}{2}{2}
```

```matlabTextOutput
deep200 = 200
```

# Conversion

You can convert between numeric arrays and cells when dimensions match.


Numeric array

```matlab
A = [10, 20;
     30, 40]
```

```matlabTextOutput
A = 2x2
    10    20
    30    40

```


 Convert to cell array

```matlab
Acell = num2cell(A)
```


| |1|2|
|:--:|:--:|:--:|
|1|10|20|
|2|30|40|



Convert back to numeric (if all cells contain scalars)

```matlab
Anum = cell2mat(Acell)
```

```matlabTextOutput
Anum = 2x2
    10    20
    30    40

```


