class Attendance:
    total_students = 0

    def __init__(self, name):
        self.name = name
        Attendance.total_students += 1

    @classmethod
    def get_total_students(cls):
        return cls.total_students


name1 = input("Enter first student name: ")
name2 = input("Enter second student name: ")
s1 = Attendance(name1)
s2 = Attendance(name2)

print(Attendance.get_total_students())