from django import forms
from django.contrib.auth.forms import UserCreationForm
from core.models import User, Review
from django.core.validators import validate_email
from django.core.exceptions import ValidationError
from datetime import date

class CustomUserCreationForm(UserCreationForm):
    email = forms.EmailField(required=True, label='Электронная почта')
    phone = forms.CharField(
        required=True,
        label='Телефон',
        help_text='Формат: +375 (29) 123-45-67'
    )
    birth_date = forms.DateField(
        required=True,
        label='Дата рождения',
        widget=forms.DateInput(attrs={'type': 'date'}),
        help_text='Введите дату рождения (вам должно быть 18+)'
    )

    class Meta:
        model = User
        fields = ('username', 'email', 'phone', 'birth_date', 'password1', 'password2')
        labels = {
            'username': 'Имя пользователя',
            'password1': 'Пароль',
            'password2': 'Подтверждение пароля',
        }

    def clean_email(self):
        email = self.cleaned_data.get('email')
        validate_email(email)
        if User.objects.filter(email=email).exists():
            raise ValidationError('Пользователь с таким email уже существует.')
        return email

    def clean_birth_date(self):
        birth_date = self.cleaned_data.get('birth_date')
        today = date.today()
        age = today.year - birth_date.year - ((today.month, today.day) < (birth_date.month, birth_date.day))
        if age < 18:
            raise ValidationError('Вам должно быть не менее 18 лет.')
        return birth_date

    def clean_phone(self):
        phone = self.cleaned_data.get('phone')
        import re
        pattern = r'^\+375 \(?(17|25|29|33|44)\)? \d{3}-\d{2}-\d{2}$'
        if not re.match(pattern, phone):
            raise ValidationError('Телефон должен быть в формате +375 (29) 123-45-67')
        return phone

    def save(self, commit=True):
        user = super().save(commit=False)
        birth_date = self.cleaned_data.get('birth_date')
        today = date.today()
        age = today.year - birth_date.year - ((today.month, today.day) < (birth_date.month, birth_date.day))
        user.age = age
        user.birth_date = birth_date
        user.email = self.cleaned_data.get('email')
        user.phone = self.cleaned_data.get('phone')
        if commit:
            user.save()
        return user

class ReviewForm(forms.ModelForm):
    class Meta:
        model = Review
        fields = ['rating', 'text']

    def clean_rating(self):
        rating = self.cleaned_data['rating']
        if rating < 1 or rating > 5:
            raise forms.ValidationError("Оценка должна быть от 1 до 5.")
        return rating

LOGGING = {
    'version': 1,
    'disable_existing_loggers': False,
    'formatters': {
        'verbose': {
            'format': '{levelname} {asctime} {module} {message}',
            'style': '{',
        },
        'simple': {
            'format': '{levelname} {message}',
            'style': '{',
        },
    },
    'handlers': {
        'console': {
            'class': 'logging.StreamHandler',
            'formatter': 'simple',
        },
        'file': {
            'class': 'logging.FileHandler',
            'filename': 'django.log',
            'formatter': 'verbose',
        },
    },
    'loggers': {
        'django': {
            'handlers': ['console', 'file'],
            'level': 'INFO',  # Можно менять на DEBUG, WARNING, ERROR, CRITICAL
        },
        'core': {
            'handlers': ['console', 'file'],
            'level': 'DEBUG',
            'propagate': False,
        },
    },
}