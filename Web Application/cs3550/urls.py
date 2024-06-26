"""
URL configuration for cs3550 project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from grades import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path("", views.assignments),
    path("<int:assignment_id>/", views.index),
    path("<int:assignment_id>/submissions/", views.submissions, name='submissions'),
    path("<int:assignment_id>/submit/", views.submit_form),
    path("<int:assignment_id>/grade/", views.grade),
    path("profile/", views.profile),
    path("profile/login/", views.login_form),
    path("profile/logout/", views.logout_form),
    path("uploads/<str:filename>/", views.show_upload),
    
    path("assignments.html", views.assignments),
    path("profile.html", views.profile),
    path("login.html", views.login_form),
]
