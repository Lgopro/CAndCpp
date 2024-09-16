import pandas

park_data = pandas.read_csv("Central_Park.csv")
color = park_data["Primary Fur Color"]

color_counts = color.value_counts()

gray_color_count = color_counts.get("Gray", 0)
black_color_count = color_counts.get("Black", 0)
cinnamon_color_count = color_counts.get("Cinnamon", 0)

print("Grey coloured count:", gray_color_count)
print("Black coloured count:", black_color_count)
print("Cinnamon coloured count:", cinnamon_color_count)

squirrels_in_the_park = {
    "squirrels_type" : ["Gray", "Black", "Cinnamon"],
    "squirrels_counter" : [gray_color_count, black_color_count, cinnamon_color_count]
}

central_park_data = pandas.DataFrame(squirrels_in_the_park)
central_park_data.to_csv("squirrel_count.csv", index=False)  # Saves the DataFrame to a CSV file without including the index