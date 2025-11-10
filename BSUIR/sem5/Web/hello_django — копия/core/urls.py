from django.urls import re_path, path
from django.contrib.auth import views as auth_views
from .views import index, register, medication_list, profile, news_list, news_detail, company_info, faq_list, contacts, privacy_policy, vacancy_list, review_list, add_review, promo_list, pickup_points, my_sales, available_promos, buy_medication, add_to_cart, cart, update_cart, checkout, order_success
from . import views

urlpatterns = [
    re_path(r'^$', index, name='index'),
    path('register/', register, name='register'),
    path('login/', auth_views.LoginView.as_view(template_name='registration/login.html'), name='login'),
    path('logout/', auth_views.LogoutView.as_view(next_page='/'), name='logout'),
    path('medications/', medication_list, name='medication_list'),
    path('profile/', profile, name='profile'),
    path('news/', news_list, name='news_list'),
    path('news/<int:pk>/', news_detail, name='news_detail'),
    path('company/', company_info, name='company_info'),
    path('faq/', faq_list, name='faq'),
    path('contacts/', contacts, name='contacts'),
    path('privacy/', privacy_policy, name='privacy_policy'),
    path('vacancies/', vacancy_list, name='vacancy_list'),
    path('reviews/', review_list, name='review_list'),
    path('reviews/add/', add_review, name='add_review'),
    path('promos/', promo_list, name='promo_list'),
    path('pickup_points/', pickup_points, name='pickup_points'),
    path('my_sales/', my_sales, name='my_sales'),
    path('promos/available/', available_promos, name='available_promos'),
    path('medications/<int:pk>/buy/', buy_medication, name='buy_medication'),
    path('sales/', views.sales_summary, name='sales_summary'),
    re_path(r'^medications/(?P<pk>\d+)/$', views.medication_detail, name='medication_detail'),
    path('medications/create/', views.medication_create, name='medication_create'),
    path('medications/<int:pk>/update/', views.medication_update, name='medication_update'),
    path('medications/<int:pk>/delete/', views.medication_delete, name='medication_delete'),
    # Корзина
    path('medications/<int:pk>/add-to-cart/', add_to_cart, name='add_to_cart'),
    path('cart/', cart, name='cart'),
    path('cart/<int:pk>/update/', update_cart, name='update_cart'),
    path('checkout/', checkout, name='checkout'),
    path('order-success/<int:order_id>/', order_success, name='order_success'),
]
