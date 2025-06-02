import tkinter as tk
import time
import subprocess
import threading


def launch_target_app(app_path):
    """Функция для запуска целевого приложения."""
    subprocess.Popen(app_path)


def delayed_launch(root, app_path, delay=5):
    """Функция, которая ждёт заданное время, затем закрывает окно и запускает приложение."""
    time.sleep(delay)
    root.destroy()  # Закрываем окно
    launch_target_app(app_path)


def show_block_window(app_path):
    """Функция, создающая окно с сообщением о блокировке."""
    root = tk.Tk()
    root.title("Доступ ограничен")
    root.geometry("400x150")

    label = tk.Label(root, text="Приложение заблокировано.\nОно откроется через 60 секунд.", font=("Arial", 14))
    label.pack(expand=True, pady=30)

    # Запускаем отсчёт времени в отдельном потоке, чтобы не блокировать интерфейс
    threading.Thread(target=delayed_launch, args=(root, app_path), daemon=True).start()

    root.mainloop()


if __name__ == "__main__":
    # Укажите путь к приложению, которое нужно запустить
    #target_app_path = r"C:\Users\Евгений\AppData\Roaming\Telegram Desktop\Telegram.exe"
    target_app_path = r"C:\Users\Евгений\Desktop\Новая папка\Новая папка\Новая папка (3)\Новая папка (5)\Новая папка (3)\Новая папка\Новая папка\Новая папка\Новая папка\Новая папка (2)\Новая папка (2)\Новая папка\Новая папка\Новая папка (2)\Новая папка (5)\Новая папка\Telegram.lnk"
    show_block_window(target_app_path)
