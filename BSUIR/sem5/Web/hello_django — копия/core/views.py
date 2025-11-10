from django.shortcuts import render, redirect, get_object_or_404
from django.contrib.auth.decorators import login_required, user_passes_test
from .forms import CustomUserCreationForm
from .models import Medication, News, CompanyInfo, FAQ, Contact, Vacancy, Review, PromoCode, PickupPoint, Sale, PharmacyDepartment, Remedy, Supplier, Partner, Cart, Order, OrderItem
# import requests  # временно закомментировано
from django import forms
from django.db.models import Q, Sum
from django.http import HttpResponseForbidden
from django.utils import timezone
import datetime
from decimal import Decimal
from django.db.models.functions import TruncDate
import calendar
from datetime import timedelta
# import matplotlib.pyplot as plt
# import io
# import base64

def index(request):
    last_news = News.objects.order_by('-created_at').first()
    partners = Partner.objects.all()
    medications = Medication.objects.all()[:6]  # Показываем первые 6 медикаментов
    now = timezone.localtime()
    year = now.year
    month = now.month
    cal = calendar.Calendar(firstweekday=0)  # 0 - понедельник
    calendar_weeks = list(cal.monthdayscalendar(year, month))
    # Для UTC-3:
    now_utc_minus3 = now - timedelta(hours=3)
    context = {
        'last_news': last_news,
        'partners': partners,
        'medications': medications,
        'now': now,
        'now_utc_minus3': now_utc_minus3,
        'calendar_weeks': calendar_weeks,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    }
    return render(request, 'core/index.html', context)

def register(request):
    if request.method == 'POST':
        form = CustomUserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('login')
    else:
        form = CustomUserCreationForm()
    return render(request, 'registration/register.html', {'form': form})

def medication_list(request):
    search_query = request.GET.get('q', '')
    sort = request.GET.get('sort', '')
    department_id = request.GET.get('department', '')
    medications = Medication.objects.all()
    departments = PharmacyDepartment.objects.all()
    if department_id:
        medications = medications.filter(department_id=department_id)
    if search_query:
        medications = medications.filter(name__icontains=search_query)
    if sort == 'price_asc':
        medications = medications.order_by('price')
    elif sort == 'price_desc':
        medications = medications.order_by('-price')
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    # Для каждого медикамента вычисляем created_at и updated_at в UTC-3
    for med in medications:
        med.created_at_utc3 = med.created_at - timedelta(hours=3) if med.created_at else None
        med.updated_at_utc3 = med.updated_at - timedelta(hours=3) if med.updated_at else None
    return render(request, 'core/medications_list.html', {
        'medications': medications,
        'departments': departments,
        'selected_department': department_id,
        'search_query': search_query,
        'sort': sort,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@login_required
def profile(request):
    now = timezone.localtime()
    year = now.year
    month = now.month
    cal = calendar.Calendar(firstweekday=0)
    calendar_weeks = list(cal.monthdayscalendar(year, month))
    now_utc_minus3 = now - timedelta(hours=3)
    employee_suppliers = []
    if getattr(request.user, 'role', None) == 'employee':
        try:
            employee = request.user.employee
            department = employee.department
            employee_suppliers = Supplier.objects.filter(medications__department=department).distinct()
        except Exception:
            employee_suppliers = []
    return render(request, 'core/profile.html', {
        'now': now,
        'now_utc_minus3': now_utc_minus3,
        'calendar_weeks': calendar_weeks,
        'TIME_ZONE': timezone.get_current_timezone_name(),
        'employee_suppliers': employee_suppliers,
    })

def news_list(request):
    news = News.objects.order_by('-created_at')
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/news_list.html', {
        'news': news,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

def news_detail(request, pk):
    article = News.objects.get(pk=pk)
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/news_detail.html', {
        'article': article,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

def company_info(request):
    info = CompanyInfo.objects.first()
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/company_info.html', {
        'info': info,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

def faq_list(request):
    faqs = FAQ.objects.all().order_by('-created_at')
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/faq_list.html', {
        'faqs': faqs,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

def contacts(request):
    contacts = Contact.objects.select_related('employee', 'employee__user').all()
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/contacts.html', {
        'contacts': contacts,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

def vacancy_list(request):
    vacancies = Vacancy.objects.all().order_by('-created_at')
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/vacancy_list.html', {
        'vacancies': vacancies,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

def privacy_policy(request):
    # Получение случайной цитаты с нового API
    quote = "Не удалось получить цитату."
    # try:
    #     response = requests.get("https://zenquotes.io/api/random", timeout=5)
    #     if response.status_code == 200:
    #         data = response.json()
    #         if isinstance(data, list) and len(data) > 0:
    #             quote = f"{data[0].get('q', '')} — {data[0].get('a', '')}"
    # except Exception:
    #     pass

    # API 2: Погода в Минске
    weather = None
    # try:
    #     resp = requests.get(f'https://wttr.in/Шклов?format=3', timeout=7)
    #     if resp.status_code == 200:
    #        weather = resp.text
    # except Exception:
    weather = "Не удалось получить погоду."

    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/privacy_policy.html', {
        'quote': quote,
        'weather': weather,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

class ReviewForm(forms.ModelForm):
    class Meta:
        model = Review
        fields = ['rating', 'text']
        widgets = {
            'rating': forms.Select(choices=[(i, i) for i in range(1, 6)]),
            'text': forms.Textarea(attrs={'rows': 4}),
        }

def review_list(request):
    reviews = Review.objects.select_related('user').order_by('-created_at')
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    has_review = False
    if request.user.is_authenticated and not request.user.is_superuser and getattr(request.user, 'role', None) != 'employee':
        has_review = reviews.filter(user=request.user).exists()
    return render(request, 'core/review_list.html', {
        'reviews': reviews,
        'has_review': has_review,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@login_required
def add_review(request):
    # Проверка: есть ли уже отзыв от этого пользователя
    if Review.objects.filter(user=request.user).exists():
        return redirect('review_list')
    if request.method == 'POST':
        form = ReviewForm(request.POST)
        if form.is_valid():
            review = form.save(commit=False)
            review.user = request.user
            review.save()
            return redirect('review_list')
    else:
        form = ReviewForm()
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/add_review.html', {
        'form': form,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

def promo_list(request):
    active_promos = PromoCode.objects.filter(active=True)
    archived_promos = PromoCode.objects.filter(active=False)
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/promo_list.html', {
        'active_promos': active_promos,
        'archived_promos': archived_promos,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@login_required
def pickup_points(request):
    points = PickupPoint.objects.all()
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/pickup_points.html', {
        'points': points,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@login_required
def my_sales(request):
    if request.user.role == 'employee':
        sales = Sale.objects.filter(employee__user=request.user)
    else:
        sales = Sale.objects.filter(customer=request.user)
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/my_sales.html', {
        'sales': sales,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@login_required
def available_promos(request):
    promos = PromoCode.objects.filter(active=True)
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/available_promos.html', {
        'promos': promos,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@login_required
def buy_medication(request, pk):
    from .models import Medication, PickupPoint, PromoCode
    if request.user.is_superuser or getattr(request.user, 'role', None) == 'employee':
        return HttpResponseForbidden("Сотрудник и администратор не могут совершать покупки.")
    med = Medication.objects.get(pk=pk)
    error = None
    pickup_points = PickupPoint.objects.all()
    promo_codes = PromoCode.objects.filter(active=True, expires_at__gt=timezone.now())
    if request.method == 'POST':
        quantity = int(request.POST.get('quantity', 1))
        pickup_point_id = request.POST.get('pickup_point')
        promo_code_id = request.POST.get('promo_code')
        if not pickup_point_id:
            error = "Выберите точку самовывоза."
        elif quantity < 1:
            error = "Количество должно быть не менее 1."
        else:
            total_price = med.price * quantity
            # Применение промокода (если выбран)
            promo = None
            if promo_code_id:
                try:
                    promo = PromoCode.objects.get(id=promo_code_id, active=True, expires_at__gt=timezone.now())
                    total_price = total_price * (Decimal('1') - promo.discount / Decimal('100'))
                except PromoCode.DoesNotExist:
                    error = "Промокод недействителен."
            if not error:
                Sale.objects.create(
                    medication=med,
                    employee=None,
                    customer=request.user,
                    quantity=quantity,
                    total_price=total_price
                )
                return redirect('my_sales')
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/buy_medication.html', {
        'medication': med,
        'error': error,
        'pickup_points': pickup_points,
        'promo_codes': promo_codes,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

def is_employee_or_superuser(user):
    return user.is_authenticated and (user.is_superuser or getattr(user, 'role', None) == 'employee')
@user_passes_test(is_employee_or_superuser)
def sales_summary(request):
    # Общая выручка
    total_revenue = Sale.objects.aggregate(total=Sum('total_price'))['total'] or 0

    # Выручка по отделам
    departments = PharmacyDepartment.objects.all()
    department_revenues = []
    dept_labels = []
    dept_data = []
    for dept in departments:
        dept_revenue = Sale.objects.filter(medication__department=dept).aggregate(total=Sum('total_price'))['total'] or 0
        department_revenues.append({'department': dept, 'revenue': dept_revenue})
        dept_labels.append(dept.name)
        dept_data.append(float(dept_revenue))

    # Выручка по датам
    sales_by_date = (
        Sale.objects
        .annotate(date_only=TruncDate('date'))
        .values('date_only')
        .annotate(total=Sum('total_price'))
        .order_by('date_only')
    )
    date_labels = [s['date_only'].strftime('%d.%m.%Y') for s in sales_by_date]
    date_data = [float(s['total']) for s in sales_by_date]

    # Временно отключены графики
    dept_chart = None
    date_chart = None

    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/sales_summary.html', {
        'total_revenue': total_revenue,
        'department_revenues': department_revenues,
        'dept_chart': dept_chart,
        'date_chart': date_chart,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@user_passes_test(is_employee_or_superuser)
def sales_charts(request):
    # Выручка по отделам
    departments = PharmacyDepartment.objects.all()
    dept_labels = []
    dept_data = []
    for dept in departments:
        dept_labels.append(dept.name)
        revenue = Sale.objects.filter(medication__department=dept).aggregate(total=Sum('total_price'))['total'] or 0
        dept_data.append(float(revenue))

    # Выручка по датам (за последние 14 дней)
    sales_by_date = (
        Sale.objects
        .annotate(date_only=TruncDate('date'))
        .values('date_only')
        .annotate(total=Sum('total_price'))
        .order_by('date_only')
    )
    date_labels = [s['date_only'].strftime('%d.%m.%Y') for s in sales_by_date]
    date_data = [float(s['total']) for s in sales_by_date]

    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/sales_charts.html', {
        'dept_labels': dept_labels,
        'dept_data': dept_data,
        'date_labels': date_labels,
        'date_data': date_data,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

def medication_detail(request, pk):
    med = Medication.objects.select_related('remedy', 'department').prefetch_related('suppliers').get(pk=pk)
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/medication_detail.html', {
        'medication': med,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })



@user_passes_test(is_employee_or_superuser)
def medication_create(request):
    departments = PharmacyDepartment.objects.all()
    remedies = Remedy.objects.all()
    suppliers = Supplier.objects.all()
    if request.method == 'POST':
        name = request.POST.get('name')
        code = request.POST.get('code')
        price = request.POST.get('price')
        instruction = request.POST.get('instruction', '')
        description = request.POST.get('description', '')
        department_id = request.POST.get('department')
        remedy_id = request.POST.get('remedy')
        supplier_ids = request.POST.getlist('suppliers')
        photo = request.FILES.get('photo')
        if name and code and price and department_id and remedy_id:
            medication = Medication.objects.create(
                name=name,
                code=code,
                price=price,
                instruction=instruction,
                description=description,
                remedy=Remedy.objects.get(pk=remedy_id),
                department=PharmacyDepartment.objects.get(pk=department_id),
                photo=photo,
            )
            if supplier_ids:
                medication.suppliers.set(supplier_ids)
        return redirect('medication_list')
    return render(request, 'core/medication_create.html', {
        'departments': departments,
        'remedies': remedies,
        'suppliers': suppliers,
    })

@user_passes_test(is_employee_or_superuser)
def medication_update(request, pk):
    med = get_object_or_404(Medication, pk=pk)
    departments = PharmacyDepartment.objects.all()
    remedies = Remedy.objects.all()
    suppliers = Supplier.objects.all()
    if request.method == 'POST':
        med.name = request.POST.get('name', med.name)
        med.code = request.POST.get('code', med.code)
        med.price = request.POST.get('price', med.price)
        med.instruction = request.POST.get('instruction', med.instruction)
        med.description = request.POST.get('description', med.description)
        department_id = request.POST.get('department')
        remedy_id = request.POST.get('remedy')
        supplier_ids = request.POST.getlist('suppliers')
        if department_id:
            med.department = PharmacyDepartment.objects.get(pk=department_id)
        if remedy_id:
            med.remedy = Remedy.objects.get(pk=remedy_id)
        if request.FILES.get('photo'):
            med.photo = request.FILES.get('photo')
        med.save()
        if supplier_ids:
            med.suppliers.set(supplier_ids)
        return redirect('medication_list')
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    return render(request, 'core/medication_update.html', {
        'medication': med,
        'departments': departments,
        'remedies': remedies,
        'suppliers': suppliers,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@user_passes_test(is_employee_or_superuser)
def medication_delete(request, pk):
    med = get_object_or_404(Medication, pk=pk)
    if request.method == 'POST':
        med.delete()
        return redirect('medication_list')
    return redirect('medication_list')

# Корзина покупок
@login_required
def add_to_cart(request, pk):
    if request.user.is_superuser or getattr(request.user, 'role', None) == 'employee':
        return HttpResponseForbidden("Сотрудник и администратор не могут совершать покупки.")
    
    medication = get_object_or_404(Medication, pk=pk)
    cart_item, created = Cart.objects.get_or_create(
        user=request.user,
        medication=medication,
        defaults={'quantity': 1}
    )
    if not created:
        cart_item.quantity += 1
        cart_item.save()
    
    return redirect('cart')

@login_required
def cart(request):
    if request.user.is_superuser or getattr(request.user, 'role', None) == 'employee':
        return HttpResponseForbidden("Сотрудник и администратор не могут совершать покупки.")
    
    cart_items = Cart.objects.filter(user=request.user)
    total = sum(item.total_price for item in cart_items)
    
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    
    return render(request, 'core/cart.html', {
        'cart_items': cart_items,
        'total': total,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@login_required
def update_cart(request, pk):
    if request.user.is_superuser or getattr(request.user, 'role', None) == 'employee':
        return HttpResponseForbidden("Сотрудник и администратор не могут совершать покупки.")
    
    cart_item = get_object_or_404(Cart, pk=pk, user=request.user)
    action = request.POST.get('action')
    
    if action == 'increase':
        cart_item.quantity += 1
        cart_item.save()
    elif action == 'decrease' and cart_item.quantity > 1:
        cart_item.quantity -= 1
        cart_item.save()
    elif action == 'remove':
        cart_item.delete()
    
    return redirect('cart')

@login_required
def checkout(request):
    if request.user.is_superuser or getattr(request.user, 'role', None) == 'employee':
        return HttpResponseForbidden("Сотрудник и администратор не могут совершать покупки.")
    
    cart_items = Cart.objects.filter(user=request.user)
    if not cart_items.exists():
        return redirect('cart')
    
    pickup_points = PickupPoint.objects.all()
    promo_codes = PromoCode.objects.filter(active=True, expires_at__gt=timezone.now())
    
    if request.method == 'POST':
        pickup_point_id = request.POST.get('pickup_point')
        promo_code_id = request.POST.get('promo_code')
        
        if not pickup_point_id:
            return render(request, 'core/checkout.html', {
                'cart_items': cart_items,
                'pickup_points': pickup_points,
                'promo_codes': promo_codes,
                'error': 'Выберите точку самовывоза.'
            })
        
        pickup_point = get_object_or_404(PickupPoint, pk=pickup_point_id)
        total_amount = sum(item.total_price for item in cart_items)
        
        # Применение промокода
        promo_code = None
        if promo_code_id:
            try:
                promo_code = PromoCode.objects.get(id=promo_code_id, active=True, expires_at__gt=timezone.now())
                total_amount = total_amount * (Decimal('1') - promo_code.discount / Decimal('100'))
            except PromoCode.DoesNotExist:
                pass
        
        # Создание заказа
        order = Order.objects.create(
            user=request.user,
            total_amount=total_amount,
            promo_code=promo_code,
            pickup_point=pickup_point
        )
        
        # Создание позиций заказа
        for cart_item in cart_items:
            OrderItem.objects.create(
                order=order,
                medication=cart_item.medication,
                quantity=cart_item.quantity,
                price=cart_item.medication.price
            )
        
        # Очистка корзины
        cart_items.delete()
        
        return redirect('order_success', order_id=order.id)
    
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    
    return render(request, 'core/checkout.html', {
        'cart_items': cart_items,
        'pickup_points': pickup_points,
        'promo_codes': promo_codes,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })

@login_required
def order_success(request, order_id):
    order = get_object_or_404(Order, pk=order_id, user=request.user)
    
    now = timezone.localtime(timezone.now())
    now_utc = timezone.now().astimezone(datetime.timezone.utc)
    now_utc_minus3 = now_utc - datetime.timedelta(hours=3)
    
    return render(request, 'core/order_success.html', {
        'order': order,
        'now': now,
        'now_utc': now_utc,
        'now_utc_minus3': now_utc_minus3,
        'TIME_ZONE': timezone.get_current_timezone_name(),
    })
