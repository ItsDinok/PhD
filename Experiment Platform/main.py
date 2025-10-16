# This is the main entry point for all of my research code, each module will be individually runnable but this is the main one
import datacleaner
from sklearn.model_selection import train_test_split

def main():
    # TODO: Make this argument driven
    PATH = "iris.data"
    x_data, y_data = datacleaner.load_dataset(PATH)

    print(y_data)
    y_data = datacleaner.make_binary_classification(y_data, ["Iris-setosa", "Iris-versicolor"], "folded")
    print(y_data)

    if not datacleaner.lazy_check_is_numeric(y_data):
        y_data = datacleaner.label_encode(y_data)

    # NOTE: Traditional feature selection approaches aren't ideal as they can remove features which may later be
    # informative and/or useful

    x_train, x_test, y_train, y_test = train_test_split(x_data, y_data, train_size=0.8, random_state=42) 
    print("x_train shape: ", len(x_train))
    print("x_test shape: ", len(x_test))
    print("y_train shape: ", len(y_train))
    print("y_test shape: ", len(y_test))



if __name__ == "__main__":
    main()
