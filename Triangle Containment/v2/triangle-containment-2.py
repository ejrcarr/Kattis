def is_point_inside_triangle(n, big_point, small_point):
    x1, y1 = big_point["point"]
    x2, y2 = small_point["point"]
    def triangle_area(x1, y1, x2, y2, x3, y3):
        return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0)
    main_triangle_area = triangle_area(0, 0, n, 0, x1, y1)

    sub_triangle1_area = triangle_area(0, 0, n, 0, x2, y2)
    sub_triangle2_area = triangle_area(0, 0, x1, y1, x2, y2)
    sub_triangle3_area = triangle_area(n, 0, x1, y1, x2, y2)

    return main_triangle_area == sub_triangle1_area + sub_triangle2_area + sub_triangle3_area
    
n, right_x_value = map(int, input().split())

left = (0, 0)
right = (right_x_value, 0)

values = []
for i in range(n):
    x, y, weight = map(int, input().split())
    values.append(
        {
            "point": (x, y), 
            "weight": weight,
        }
    )

copy = values[:]
values.sort(key=lambda value: value["point"][1], reverse=True)
for i in range(len(values)):
    total = 0
    current = values[i]
    for j in range(i+1, len(values)):
        next = values[j]
        if is_point_inside_triangle(right_x_value, current, next):
            total += next["weight"]
    values[i]["total"] = total

for value in copy:
    print(value["total"])
        