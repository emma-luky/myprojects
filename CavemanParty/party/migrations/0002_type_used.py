# Generated by Django 4.2.4 on 2024-01-18 20:19

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('party', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='type',
            name='used',
            field=models.BooleanField(default=False),
        ),
    ]
