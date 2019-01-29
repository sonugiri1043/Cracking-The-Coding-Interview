'''
String Rotation:
Assume you have a method isSubstring which checks if one word is a substring of another.
Given two strings, S1 and S2, write code to check if S2 is a rotation of S1 using only one
call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
'''

def isSubString( s1, s2 ):
    return s1 in s2

origStr = "waterbottle"
rotStr = "erbottlewat"

def checkStringRotation( original, rotation ):
    return isSubString( original, rotation + rotation )

print checkStringRotation( origStr, rotStr )
