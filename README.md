# RuntimeCounterTerrorists

Welcome to the RuntimeCounterTerrorist COS214 Project

## Style Guide

### Naming
Variables & Parameters - Snake Case (snake_case)
Functions - Lower Camel Case (lowerCamelCase)
Classes - Upper Camel Case (UpperCamelCase)
Constat Variables - Upper Case (UPPER_CASE)

Be descriptive when naming (E.g. instead of int x for a counter, rather have int student_counter)

### Classes
- Each class MUST have a .cpp and .h file
- Each class must be encapsulated by an IFNDEF, DEF, ENDIF clause.
- Do not rely on transitive includes. Always include all external classes needed in the class where the externals are used.
- When possible, always destruct right after an object's last usage.

### Formatting
Braces, both open and close, go on their own lines (no "cuddled braces"). E.g.:
if (true)
{
  //Whatever
}
else 
{
  //Whatever
}
