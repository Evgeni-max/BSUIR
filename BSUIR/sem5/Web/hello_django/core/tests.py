from django.test import TestCase, Client
from django.urls import reverse
from django.contrib.auth import get_user_model
from .models import Review, Medication
from .forms import CustomUserCreationForm, ReviewForm

User = get_user_model()

class UserRegistrationTest(TestCase):
    def test_register_valid_user(self):
        data = {
            'username': 'testuser',
            'email': 'test@example.com',
            'phone': '+375 (29) 123-45-67',
            'birth_date': '2000-01-01',
            'password1': 'Testpass123!',
            'password2': 'Testpass123!',
        }
        form = CustomUserCreationForm(data)
        self.assertTrue(form.is_valid())
        user = form.save()
        self.assertEqual(user.email, 'test@example.com')
        self.assertEqual(user.phone, '+375 (29) 123-45-67')

    def test_register_invalid_email(self):
        data = {
            'username': 'testuser2',
            'email': 'bademail',
            'phone': '+375 (29) 123-45-67',
            'birth_date': '2000-01-01',
            'password1': 'Testpass123!',
            'password2': 'Testpass123!',
        }
        form = CustomUserCreationForm(data)
        self.assertFalse(form.is_valid())

class ReviewFormTest(TestCase):
    def test_review_form_valid(self):
        user = User.objects.create_user(username='reviewer', password='12345')
        form = ReviewForm({'rating': 5, 'text': 'Отлично!'})
        self.assertTrue(form.is_valid())

    def test_review_form_invalid_rating(self):
        form = ReviewForm({'rating': 10, 'text': 'Плохо!'})
        self.assertFalse(form.is_valid())

class ReviewViewTest(TestCase):
    def setUp(self):
        self.client = Client()
        self.user = User.objects.create_user(username='reviewer', password='12345')
        self.review = Review.objects.create(user=self.user, rating=5, text='Хорошо!')

    def test_review_list_view(self):
        response = self.client.get(reverse('review_list'))
        self.assertEqual(response.status_code, 200)
        self.assertContains(response, 'Отзывы')

    def test_add_review_requires_login(self):
        response = self.client.get(reverse('add_review'))
        self.assertEqual(response.status_code, 302)  # Redirect to login

class MedicationListViewTest(TestCase):
    def setUp(self):
        self.client = Client()
        self.user = User.objects.create_user(username='meduser', password='12345')
        Medication.objects.create(name='TestMed', code='001', price=10, description='desc')