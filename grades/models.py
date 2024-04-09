from django.db import models
from django.contrib.auth.models import User, Group

# Create your models here.
class Assignment(models.Model):
    title = models.CharField(max_length=200)
    description = models.TextField(blank=True)
    deadline = models.DateTimeField()
    weight = models.IntegerField()
    points = models.IntegerField(default=100)

class Submission(models.Model):
    assignment = models.ForeignKey(Assignment, on_delete=models.CASCADE)
    # what type of on_delete??
    author = models.ForeignKey(User, on_delete=models.CASCADE)
    grader = models.ForeignKey(User, on_delete=models.PROTECT, related_name='graded_set')
    file = models.FileField(blank=True)
    score = models.IntegerField(blank=True, null=True)