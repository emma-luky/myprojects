from django.db import models
from django.contrib.auth.models import User, Group
# Create your models here.

class Type(models.Model):
    name = models.CharField(max_length=200)
    used = models.BooleanField(default=False)

class Caveman(models.Model):
    name = models.CharField(max_length=200, blank=False, null=False)
    type = models.ForeignKey(Type, on_delete=models.CASCADE)