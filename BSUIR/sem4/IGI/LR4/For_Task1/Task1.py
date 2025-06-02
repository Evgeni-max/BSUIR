import csv
import pickle

class TreeSpecies:
    def __init__(self, name, total, healthy):
        self.name = name
        self.total = total
        self.healthy = healthy

class ForestData:
    def __init__(self, data=None):
        self.species = []
        if data:
            for item in data:
                self.add_species(item['name'], item['total'], item['healthy'])

    def add_species(self, name, total, healthy):
        self.species.append(TreeSpecies(name, total, healthy))

    # Сериализация в CSV
    def save_to_csv(self, filename):
        with open(filename, 'w', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow(['Вид', 'Всего', 'Здоровые'])
            for tree in self.species:
                writer.writerow([tree.name, tree.total, tree.healthy])

    @classmethod
    def load_from_csv(cls, filename):
        data = []
        try:
            with open(filename, 'r', encoding='utf-8') as f:
                reader = csv.DictReader(f)
                for row in reader:
                    data.append({
                        'name': row['Вид'],
                        'total': int(row['Всего']),
                        'healthy': int(row['Здоровые'])
                    })
        except FileNotFoundError:
            print("Файл не найден!")
        return cls(data)

    # Сериализация в Pickle
    def save_to_pickle(self, filename):
        with open(filename, 'wb') as f:
            pickle.dump(self.species, f)

    @classmethod
    def load_from_pickle(cls, filename):
        try:
            with open(filename, 'rb') as f:
                species = pickle.load(f)
            instance = cls()
            instance.species = species
            return instance
        except FileNotFoundError:
            print("Файл не найден!")
            return cls()

    # Вычисления
    def total_trees(self):
        return sum(tree.total for tree in self.species)

    def total_healthy(self):
        return sum(tree.healthy for tree in self.species)

    def sick_percentage(self):
        total = self.total_trees()
        return ((total - self.total_healthy()) / total * 100) if total > 0 else 0

    def species_statistics(self):
        stats = {}
        total = self.total_trees()
        for tree in self.species:
            species_total_percent = (tree.total / total * 100) if total > 0 else 0
            sick_percent = ((tree.total - tree.healthy) / tree.total * 100) if tree.total > 0 else 0
            stats[tree.name] = {
                'Процент от общего числа': species_total_percent,
                'Процент больных': sick_percent
            }
        return stats

    def find_species(self, name):
        for tree in self.species:
            if tree.name.lower() == name.lower():
                return tree
        return None

# Пример использования
if __name__ == "__main__":
    # Исходные данные
    initial_data = [
        {'name': 'Дуб', 'total': 1000, 'healthy': 800},
        {'name': 'Сосна', 'total': 1500, 'healthy': 1200},
        {'name': 'Береза', 'total': 500, 'healthy': 300}
    ]

    # Инициализация и сохранение данных
    forest = ForestData(initial_data)
    forest.save_to_csv('forest.csv')
    forest.save_to_pickle('forest.pkl')

    # Загрузка данных
    forest_csv = ForestData.load_from_csv('forest.csv')
    forest_pkl = ForestData.load_from_pickle('forest.pkl')

    # Выбор источника данных (можно изменить на forest_pkl)
    current_forest = forest_csv

    # Вычисление статистики
    print(f"1. Суммарное число деревьев: {current_forest.total_trees()}")
    print(f"2. Суммарное число здоровых: {current_forest.total_healthy()}")
    print(f"3. Процент больных деревьев: {current_forest.sick_percentage():.1f}%")

    # Статистика по видам
    print("\n4. Статистика по видам:")
    stats = current_forest.species_statistics()
    for name, data in stats.items():
        print(f"{name}:")
        print(f"  - Доля от всех деревьев: {data['Процент от общего числа']:.1f}%")
        print(f"  - Больные: {data['Процент больных']:.1f}%")

    # Поиск вида
    search = input("\nВведите вид дерева: ")
    found = current_forest.find_species(search)
    if found:
        print(f"Найдено: {found.name}")
        print(f"Всего деревьев: {found.total}")
        print(f"Здоровых: {found.healthy} ({found.healthy/found.total*100:.1f}%)")
    else:
        print("Вид не найден!")