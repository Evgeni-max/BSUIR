from django.contrib import admin
from .models import (
    User, Remedy, PharmacyDepartment, Supplier,
    Medication, Employee, Sale, PickupPoint, PromoCode, News, CompanyInfo, FAQ, Contact,
    Vacancy, Review, Partner, Cart, Order, OrderItem
)

@admin.register(User)
class UserAdmin(admin.ModelAdmin):
    list_display = ('username', 'role', 'phone', 'age')
    list_filter = ('role',)
    search_fields = ('username', 'phone')
    verbose_name = 'Пользователь'
    verbose_name_plural = 'Пользователи'

@admin.register(Remedy)
class RemedyAdmin(admin.ModelAdmin):
    list_display = ('name', 'info')
    search_fields = ('name', 'info')
    verbose_name = 'Лечащее средство'
    verbose_name_plural = 'Лечащие средства'

@admin.register(Medication)
class MedicationAdmin(admin.ModelAdmin):
    list_display = ('name', 'code', 'price', 'remedy', 'department')
    list_filter = ('remedy', 'department', 'suppliers')
    search_fields = ('name', 'code', 'description')
    filter_horizontal = ('suppliers',)
    verbose_name = 'Медикамент'
    verbose_name_plural = 'Медикаменты'

@admin.register(Sale)
class SaleAdmin(admin.ModelAdmin):
    list_display = ('medication', 'employee', 'quantity', 'total_price', 'date')
    list_filter = ('date', 'employee')
    search_fields = ('medication__name',)
    verbose_name = 'Продажа'
    verbose_name_plural = 'Продажи'

@admin.register(News)
class NewsAdmin(admin.ModelAdmin):
    list_display = ('title', 'summary', 'created_at')
    search_fields = ('title', 'summary', 'content')
    list_filter = ('created_at',)

@admin.register(CompanyInfo)
class CompanyInfoAdmin(admin.ModelAdmin):
    list_display = ('name',)
    search_fields = ('name', 'description', 'requisites')
    verbose_name = 'О компании'
    verbose_name_plural = 'О компании'

@admin.register(FAQ)
class FAQAdmin(admin.ModelAdmin):
    list_display = ('question', 'created_at')
    search_fields = ('question', 'answer')
    list_filter = ('created_at',)
    verbose_name = 'Вопрос-ответ'
    verbose_name_plural = 'Вопросы-ответы'

@admin.register(Contact)
class ContactAdmin(admin.ModelAdmin):
    list_display = ('employee', 'position', 'phone', 'email')
    search_fields = ('employee__user__username', 'position', 'phone', 'email')
    verbose_name = 'Контакт'
    verbose_name_plural = 'Контакты'

@admin.register(Vacancy)
class VacancyAdmin(admin.ModelAdmin):
    list_display = ('title', 'created_at')
    search_fields = ('title', 'description')
    list_filter = ('created_at',)
    verbose_name = 'Вакансия'
    verbose_name_plural = 'Вакансии'

@admin.register(Review)
class ReviewAdmin(admin.ModelAdmin):
    list_display = ('user', 'rating', 'text', 'created_at')
    search_fields = ('user__username', 'text')
    list_filter = ('rating', 'created_at')
    verbose_name = 'Отзыв'
    verbose_name_plural = 'Отзывы'

@admin.register(Partner)
class PartnerAdmin(admin.ModelAdmin):
    list_display = ('name', 'website_url', 'created_at')
    search_fields = ('name', 'description')
    list_filter = ('created_at',)
    verbose_name = 'Партнер'
    verbose_name_plural = 'Партнеры'

@admin.register(Cart)
class CartAdmin(admin.ModelAdmin):
    list_display = ('user', 'medication', 'quantity', 'created_at')
    list_filter = ('created_at',)
    search_fields = ('user__username', 'medication__name')
    verbose_name = 'Корзина'
    verbose_name_plural = 'Корзины'

class OrderItemInline(admin.TabularInline):
    model = OrderItem
    extra = 0

@admin.register(Order)
class OrderAdmin(admin.ModelAdmin):
    list_display = ('id', 'user', 'status', 'total_amount', 'created_at')
    list_filter = ('status', 'created_at')
    search_fields = ('user__username',)
    inlines = [OrderItemInline]
    verbose_name = 'Заказ'
    verbose_name_plural = 'Заказы'

@admin.register(OrderItem)
class OrderItemAdmin(admin.ModelAdmin):
    list_display = ('order', 'medication', 'quantity', 'price')
    list_filter = ('order__status',)
    search_fields = ('medication__name', 'order__user__username')
    verbose_name = 'Позиция заказа'
    verbose_name_plural = 'Позиции заказов'

admin.site.register(PharmacyDepartment)
admin.site.register(Supplier)
admin.site.register(Employee)
admin.site.register(PickupPoint)
admin.site.register(PromoCode)
