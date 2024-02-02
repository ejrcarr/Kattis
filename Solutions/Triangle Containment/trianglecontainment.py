

def calculate_slope(point1, point2):
    # print(point1, point2)
    x1, y1 = point1
    x2, y2 = point2
    if (x2 - x1) == 0:
         return "undefined"
    return (y2 - y1) / (x2 - x1)

def calculate_y_intercept(point1, point2):

    x1, y1 = point1
    slope = calculate_slope(point1, point2)
    if slope == "undefined":
        return max(y1, point2[1])
    y_intercept = y1 - slope * x1
    return y_intercept

def is_point_to_right(point, slope, y_intercept):
    x, y = point
    expected_y = slope * x + y_intercept
    return y < expected_y
    
def is_point_under_triangle(triangle_value, point):
    x, y = point
    left_slope = triangle_value["left_slope"]
    right_slope = triangle_value["right_slope"]
    right_intercept = triangle_value["right_intercept"]

    if left_slope == "undefined":
        is_point_under_right = is_point_to_right(point, right_slope, right_intercept)

        return triangle_value["point"][0] < x and is_point_under_right
    if right_slope == "undefined":
        is_point_under_left = is_point_to_right(point, left_slope, 0)
        return triangle_value["point"][0] > x and is_point_under_left

    is_point_under_left = is_point_to_right(point, left_slope, 0)

    is_point_under_right = not is_point_to_right(point, right_slope, right_intercept)

    return is_point_under_left and is_point_under_right


    
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
            "left_slope": calculate_slope((x, y), left),
            "right_slope": calculate_slope((x, y), right),
            "right_intercept": calculate_y_intercept((x, y), right)
        }
    )

copy = values[:]
values.sort(key=lambda value: value["point"][1], reverse=True)
for i in range(len(values)):
    total = 0
    current = values[i]
    for j in range(i+1, len(values)):
        next = values[j]
        if is_point_under_triangle(current, next["point"]):
            total += next["weight"]
    values[i]["total"] = total

for value in copy:
    print(value["total"])
        