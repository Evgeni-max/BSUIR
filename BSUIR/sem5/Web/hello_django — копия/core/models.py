from django.db import models
from django.contrib.auth.models import AbstractUser
from django.core.validators import RegexValidator, MinValueValidator
from django.utils import timezone

class User(AbstractUser):
    ROLE_CHOICES = (
        ('employee', 'Сотрудник'),
        ('customer', 'Покупатель'),
    )
    role = models.CharField(max_length=10, choices=ROLE_CHOICES, default='customer', verbose_name='Роль')
    email = models.EmailField('Электронная почта', unique=True, blank=True, null=True)
    phone = models.CharField(
        max_length=20,
        verbose_name='Телефон',
        blank=True, null=True,  # добавлено
        validators=[
            RegexValidator(
                regex=r'^\+375 \(?(17|25|29|33|44)\)? \d{3}-\d{2}-\d{2}$',
                message='Формат: +375 (29) 123-45-67'
            )
        ]
    )
    age = models.PositiveIntegerField(
        verbose_name='Возраст',
        blank=True, null=True,  # добавлено
        validators=[MinValueValidator(18)]
    )
    birth_date = models.DateField(verbose_name='Дата рождения', blank=True, null=True)

    def __str__(self):
        return self.username

class Remedy(models.Model):
    name = models.CharField(max_length=100, verbose_name='Название лечащего средства')
    info = models.TextField(verbose_name='Информация')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.name

class PharmacyDepartment(models.Model):
    name = models.CharField(max_length=100, verbose_name='Отдел')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.name

class Supplier(models.Model):
    name = models.CharField(max_length=100, verbose_name='Поставщик')
    contact_info = models.TextField(verbose_name='Контактная информация')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.name

class Medication(models.Model):
    remedy = models.ForeignKey(Remedy, on_delete=models.CASCADE, verbose_name='Лечащее средство')
    department = models.ForeignKey(PharmacyDepartment, on_delete=models.CASCADE, verbose_name='Отдел')
    code = models.CharField(max_length=50, unique=True, verbose_name='Код')
    name = models.CharField(max_length=100, verbose_name='Название')
    instruction = models.TextField(verbose_name='Инструкция')
    description = models.TextField(verbose_name='Описание')
    price = models.DecimalField(max_digits=10, decimal_places=2, verbose_name='Стоимость')
    photo = models.ImageField(upload_to='medications/', verbose_name='Фото')
    suppliers = models.ManyToManyField('Supplier', related_name='medications', verbose_name='Поставщики')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.name

class Employee(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE, verbose_name='Пользователь')
    department = models.ForeignKey(PharmacyDepartment, on_delete=models.CASCADE, verbose_name='Отдел')

    def __str__(self):
        return self.user.username

class Sale(models.Model):
    medication = models.ForeignKey(Medication, on_delete=models.CASCADE, verbose_name='Медикамент')
    employee = models.ForeignKey(Employee, on_delete=models.CASCADE, verbose_name='Сотрудник', null=True, blank=True)
    customer = models.ForeignKey(User, on_delete=models.CASCADE, verbose_name='Покупатель', null=True, blank=True)  # Новое поле
    quantity = models.PositiveIntegerField(verbose_name='Количество')
    total_price = models.DecimalField(max_digits=10, decimal_places=2, verbose_name='Сумма')
    date = models.DateTimeField(auto_now_add=True, verbose_name='Дата')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')  # добавлено

    def __str__(self):
        return f'{self.medication.name} ({self.date})'

class PickupPoint(models.Model):
    address = models.CharField(max_length=255, verbose_name='Адрес')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.address

class PromoCode(models.Model):
    code = models.CharField(max_length=50, unique=True, verbose_name='Промокод')
    discount = models.DecimalField(max_digits=5, decimal_places=2, verbose_name='Скидка')
    active = models.BooleanField(default=True, verbose_name='Активен')
    expires_at = models.DateTimeField(verbose_name='Действует до', null=True, blank=True)  # новое поле
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def is_expired(self):
        return self.expires_at and timezone.now() > self.expires_at

    def __str__(self):
        return self.code

class ArchivedPromoCode(models.Model):
    code = models.CharField(max_length=50, verbose_name='Промокод')
    discount = models.DecimalField(max_digits=5, decimal_places=2, verbose_name='Скидка')
    expired_at = models.DateTimeField(verbose_name='Дата истечения')
    archived_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата архивации')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.code

class News(models.Model):
    title = models.CharField(max_length=200, verbose_name='Заголовок')
    summary = models.CharField(max_length=300, verbose_name='Краткое содержание')
    image = models.ImageField(upload_to='news/', verbose_name='Картинка', blank=True, null=True)
    content = models.TextField(verbose_name='Полный текст')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата публикации')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.title

class CompanyInfo(models.Model):
    name = models.CharField(max_length=255, verbose_name='Название компании')
    description = models.TextField(verbose_name='Описание')
    history = models.TextField(verbose_name='История по годам', blank=True)
    requisites = models.TextField(verbose_name='Реквизиты', blank=True)
    logo = models.ImageField(upload_to='company_logos/', verbose_name='Логотип', blank=True, null=True)
    video_url = models.URLField(verbose_name='Видео (ссылка)', blank=True)
    certificate = models.TextField(verbose_name='Сертификат', blank=True, help_text='Текст сертификата компании')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.name

class FAQ(models.Model):
    question = models.CharField(max_length=255, verbose_name='Вопрос')
    answer = models.TextField(verbose_name='Ответ')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.question

class Contact(models.Model):
    employee = models.OneToOneField(Employee, on_delete=models.CASCADE, verbose_name='Сотрудник')
    photo = models.ImageField(upload_to='contacts/', verbose_name='Фото', blank=True, null=True)
    position = models.CharField(max_length=100, verbose_name='Должность')
    description = models.TextField(verbose_name='Описание выполняемых работ', blank=True)
    phone = models.CharField(
        max_length=20,
        verbose_name='Телефон',
        validators=[
            RegexValidator(
                regex=r'^\+375 \(?(17|25|29|33|44)\)? \d{3}-\d{2}-\d{2}$',
                message='Формат: +375 (29) 123-45-67'
            )
        ]
    )
    email = models.EmailField(verbose_name='Почта')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return f'{self.employee.user.get_full_name()} ({self.position})'

class Vacancy(models.Model):
    title = models.CharField(max_length=200, verbose_name='Должность')
    description = models.TextField(verbose_name='Описание')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата публикации')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.title

class Review(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, verbose_name='Пользователь')
    rating = models.PositiveSmallIntegerField(verbose_name='Оценка')
    text = models.TextField(verbose_name='Текст отзыва')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return f"{self.user.username} ({self.rating})"

class Partner(models.Model):
    name = models.CharField(max_length=200, verbose_name='Название компании')
    logo = models.ImageField(upload_to='partners/', verbose_name='Логотип')
    website_url = models.URLField(verbose_name='Ссылка на сайт')
    description = models.TextField(verbose_name='Описание', blank=True)
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return self.name

class Cart(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, verbose_name='Пользователь')
    medication = models.ForeignKey(Medication, on_delete=models.CASCADE, verbose_name='Медикамент')
    quantity = models.PositiveIntegerField(default=1, verbose_name='Количество')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата добавления')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    class Meta:
        unique_together = ['user', 'medication']

    def __str__(self):
        return f"{self.user.username} - {self.medication.name} ({self.quantity})"

    @property
    def total_price(self):
        return self.medication.price * self.quantity

class Order(models.Model):
    STATUS_CHOICES = (
        ('pending', 'Ожидает оплаты'),
        ('paid', 'Оплачен'),
        ('processing', 'В обработке'),
        ('shipped', 'Отправлен'),
        ('delivered', 'Доставлен'),
        ('cancelled', 'Отменен'),
    )
    
    user = models.ForeignKey(User, on_delete=models.CASCADE, verbose_name='Пользователь')
    status = models.CharField(max_length=20, choices=STATUS_CHOICES, default='pending', verbose_name='Статус')
    total_amount = models.DecimalField(max_digits=10, decimal_places=2, verbose_name='Общая сумма')
    promo_code = models.ForeignKey(PromoCode, on_delete=models.SET_NULL, null=True, blank=True, verbose_name='Промокод')
    pickup_point = models.ForeignKey(PickupPoint, on_delete=models.CASCADE, verbose_name='Точка самовывоза')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата создания')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата изменения')

    def __str__(self):
        return f"Заказ #{self.id} - {self.user.username}"

class OrderItem(models.Model):
    order = models.ForeignKey(Order, on_delete=models.CASCADE, related_name='items', verbose_name='Заказ')
    medication = models.ForeignKey(Medication, on_delete=models.CASCADE, verbose_name='Медикамент')
    quantity = models.PositiveIntegerField(verbose_name='Количество')
    price = models.DecimalField(max_digits=10, decimal_places=2, verbose_name='Цена за единицу')

    def __str__(self):
        return f"{self.medication.name} x{self.quantity}"

    @property
    def total_price(self):
        return self.price * self.quantity